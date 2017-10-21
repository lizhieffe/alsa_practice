#include <alsa/asoundlib.h>
#include <iostream>

#include "print_alsa_info.h"

using std::cerr;
using std::cout;
using std::endl;

int main() {
  cout << "Started..." << endl;

  PrintAlsaInfo();


  int rc;
  snd_pcm_t *handle;
  snd_pcm_hw_params_t *params;
  unsigned int val, val2;
  int dir;
  snd_pcm_uframes_t frames;

  // Open PCM device for playback
  rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
  if (rc < 0) {
    cerr << "Unable to open pcm device: " << snd_strerror(rc) << endl;
    exit(1);
  }

  // Allocate a hardware parameters object.
  snd_pcm_hw_params_alloca(&params);

  // Set the desired hardware parameters.

  // Interleaved mode.
  snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);

  // Signed 16-bit little-endian format.
  snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);

  // Two channels (stereo).
  snd_pcm_hw_params_set_channels(handle, params, 2);

  // 44100 bits/second sampling rate (CD quality).
  val = 44100;
  snd_pcm_hw_params_set_rate_near(handle, params, &val, &dir);

  // Write the parameters to the driver.
  rc = snd_pcm_hw_params(handle, params);
  if (rc < 0) {
    cerr << "Unable to set hw parameters: (" << rc << ") "
         << snd_strerror(rc) << endl;
    exit(1);
  }


  // Display information about the PCM interface.
  cout << "PCM handle name = " << snd_pcm_name(handle) << endl;
  cout << "PCM state = " << snd_pcm_state_name(snd_pcm_state(handle));
  
  snd_pcm_hw_params_get_access(params, (snd_pcm_access_t *) &val);
  cout << "access type = " << snd_pcm_access_name((snd_pcm_access_t)val)
       << endl;

  snd_pcm_hw_params_get_format(params, (snd_pcm_format_t *)&val);
  cout << "format = '" << snd_pcm_format_name((snd_pcm_format_t)val) << "' ("
       << snd_pcm_format_description((snd_pcm_format_t)val) << ")" << endl;
}
