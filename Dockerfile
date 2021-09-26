FROM ubuntu

RUN apt-get update

RUN apt-get install software-properties-common -y

RUN add-apt-repository ppa:mscore-ubuntu/mscore3-stable

RUN apt update

RUN apt install musescore3 -y

RUN ln -s /usr/bin/musescore3 /usr/bin/musescore

RUN apt install -y git

RUN git clone https://github.com/mathigatti/RealTimeSingingSynthesizer.git

WORKDIR "/RealTimeSingingSynthesizer/synthesisSoftware/libespeak-NG/"

RUN apt install -y make autoconf automake libtool pkg-config

RUN apt install -y gcc libsonic-dev ruby-ronn ruby-kramdown

RUN ls

RUN ./autogen.sh

RUN ./configure --prefix=/usr

RUN make

RUN ln -s /RealTimeSingingSynthesizer/synthesisSoftware/libespeak-NG/src/.libs/libespeak-ng.so /usr/lib/libespeak-ng.so 

WORKDIR "/RealTimeSingingSynthesizer/synthesisSoftware/Sinsy-NG-0.0.1"

RUN ls

RUN mkdir build

WORKDIR "/RealTimeSingingSynthesizer/synthesisSoftware/Sinsy-NG-0.0.1/build"

RUN ls

RUN apt install -y cmake

RUN ls

RUN apt install -y build-essential

RUN apt install -y libsndfile1-dev

RUN apt install -y libsamplerate-dev

RUN cat ../CMakeLists.txt

RUN cmake ..

RUN make

WORKDIR "/RealTimeSingingSynthesizer"

RUN apt install -y python3-pip

ADD requirements.txt .

RUN python3 -m pip install --upgrade pip

RUN python3 -m pip install -r requirements.txt

RUN ln -s /RealTimeSingingSynthesizer/synthesisSoftware/Sinsy-NG-0.0.1/build/libsinsy.so /lib/libsinsy.so

RUN ln -s /RealTimeSingingSynthesizer/synthesisSoftware/libespeak-NG/src/.libs/libespeak-ng.so.1 /usr/lib/libespeak-ng.so.1

RUN cp -r /RealTimeSingingSynthesizer/synthesisSoftware/libespeak-NG/espeak-ng-data /usr/share/

RUN apt-get -y update && apt-get -y install gcc && apt-get -y install libsndfile1-dev && apt-get -y install ffmpeg

RUN python3 -m pip install pydub starlette uvicorn ujson aiofiles

ADD Voice.py .
ADD voice-api.py . 

ENTRYPOINT ["python3", "-X", "utf8", "voice-api.py"]



