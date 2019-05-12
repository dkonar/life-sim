FROM debian:stretch
RUN apt-get -qq -y update && apt-get -qq install -y --no-install-recommends python python-pip
WORKDIR /srv/www
CMD ["python", "-m", "SimpleHTTPServer", "8000"]
EXPOSE 8000
