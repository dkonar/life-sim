FROM trzeci/emscripten
ADD ./ /src
RUN apt-get -qq -y update && apt-get -qq install -y --no-install-recommends inotify-tools
WORKDIR /src
RUN make
CMD ["make", "watch"]
