from random import choice
import os

from starlette.applications import Starlette
from starlette.responses import FileResponse
import uvicorn
from pydub import AudioSegment

from Composer import compose
from Voice import renderizeVoice

def wav2mp3(path_to_file):
    final_audio = AudioSegment.from_wav(file=path_to_file)
    path_to_file = path_to_file.replace(".wav",".mp3")
    final_audio.export(path_to_file, format="mp3")
    return path_to_file 

app = Starlette(debug=False)

# Needed to avoid cross-domain issues
response_header = {
    'Access-Control-Allow-Origin': '*',
}

@app.route('/voice', methods=['GET','POST'])
async def voice(request):
    if request.method == 'GET':
        params = request.query_params
    elif request.method == 'POST':
        params = await request.json()

    lyrics = params.get('lyrics', 'oo ')
    notes = params.get('notes', [0])
    octave = params.get("octave", 6)
    dur = params.get('dur', [1])
    tempo = params.get('tempo', 120)
    lang = params.get('lang', 'es')
    scale = params.get('scale', [0,2,4,5,7,9,11])
    root_note = params.get('root', 0) # C is the root note
    notes = list(map(lambda x: x + root_note,notes))

    # hardcodear filename
    filename = 'output.wav'

    renderizeVoice(filename,lyrics,notes,dur,tempo,scale,lang)
    return FileResponse(wav2mp3(filename), headers=response_header)


@app.route('/midi', methods=['GET','POST'])
async def midi(request):
    if request.method == 'GET':
        params = request.query_params
    elif request.method == 'POST':
        params = await request.json()

    lyrics = params.get('lyrics', 'oo ')
    notes = params.get('notes', [0])
    octave = params.get("octave", 6)
    dur = params.get('dur', [1])
    tempo = params.get('tempo', 120)
    lang = params.get('lang', 'es')
    scale = params.get('scale', [0,2,4,5,7,9,11])
    root_note = params.get('root', 0) # C is the root note
    notes = list(map(lambda x: x + root_note,notes))

    filename = 'output.mid'
    compose(notes, dur, scale, filename)
    return FileResponse(filename, headers=response_header)

@app.route('/sheet', methods=['GET','POST'])
async def sheet(request):
    filename="tmp/last_voice.xml"
    return FileResponse(filename, headers=response_header)

@app.route('/text', methods=['GET','POST'])
async def texto(request):
    textos = ["hola solcha esto \n es un texto",
            "esto es otro \n texto, tiene comas",
            "el sombrero mágico \n esta hablando por \n allá atrás, le \n gustan las tíldes"]
    return {"texto": choice(textos)}

@app.route('/random-translate',methods=['GET','POST'])
async def random_translate(request):
    if request.method == 'GET':
        params = request.query_params
    elif request.method == 'POST':
        params = await request.json()

    if 'texto' in params.keys():
        langs = ['en','es','de','zh']
        #response = gs.translate(params['texto'], choice(langs))
        response = params['texto']
        return {"texto": response}
    else:
        return 'por favor mandame un json con el campo "texto"'

if __name__ == '__main__':
    uvicorn.run(app, host='0.0.0.0', port=int(os.environ.get('PORT', 8080)))