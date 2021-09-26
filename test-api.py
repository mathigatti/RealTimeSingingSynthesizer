import requests
import json

def voice(notes=[0,1,2,3,4,5,4,3,2,1,0], dur=[1], lyrics="oo ", file="song.mp3", octave=6, lang="en", tempo=120):
  headers = {
      'Content-Type': 'application/json',
  }

  data = {
          "notes": notes,
          "dur": dur,
          "lyrics": lyrics.split("\n"),
          "octave": octave,
          "lang": lang,
          "tempo": tempo
  }

  data = json.dumps(data)

  response = requests.post('http://localhost:8080/voice', headers=headers, data=data)

  with open(file,'wb') as f:
    f.write(response.content)
  return file

file_path = voice(lyrics="This is a test audio file")