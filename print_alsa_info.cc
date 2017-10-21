#include "print_alsa_info.h"

#include <alsa/asoundlib.h>
#include <iostream>

using std::cout;
using std::endl;

void PrintAlsaInfo() {
  cout << "ALSA lib version: " << SND_LIB_VERSION_STR << endl;

  cout << "PCM stream types:" << endl;
  for (int i = 0; i <= SND_PCM_STREAM_LAST; i++) {
    cout << "\t" << snd_pcm_stream_name((snd_pcm_stream_t)i) << endl;
  }

  cout << "PCM access types:" << endl;
  for (int i = 0; i <= SND_PCM_ACCESS_LAST; i++) {
    cout << "\t" << snd_pcm_access_name((snd_pcm_access_t)i) << endl;
  }

  cout << "PCM formats:" << endl;
  for (int i = 0; i <= SND_PCM_FORMAT_LAST; i++) {
    if (snd_pcm_format_name((snd_pcm_format_t)i) != NULL) {
      cout << "\t" << snd_pcm_format_name((snd_pcm_format_t)i)
           << "\t" << snd_pcm_format_description((snd_pcm_format_t)i)
           << endl;
    }
  }

  cout << "PCM subformats:" << endl;
  for (int i = 0; i <= SND_PCM_FORMAT_LAST; i++) {
    if (snd_pcm_subformat_name((snd_pcm_subformat_t)i) != NULL) {
      cout << "\t" << snd_pcm_subformat_name((snd_pcm_subformat_t)i)
           << "\t" << snd_pcm_subformat_description((snd_pcm_subformat_t)i)
           << endl;
    }
  }

  cout << "PCM states:" << endl;
  for (int i = 0; i <= SND_PCM_STATE_LAST; i++) {
    cout << "\t" << snd_pcm_state_name((snd_pcm_state_t)i) << endl;
  }

  cout << "Finished printing ALSA information." << endl;
  cout << "===========================================================" << endl;
  cout << endl;
}
