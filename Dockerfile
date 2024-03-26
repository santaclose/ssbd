FROM ubuntu:22.04 as build

LABEL org.opencontainers.image.authors="Santiago <san@san.com>"
LABEL org.opencontainers.image.source="https://github.com/santaclose/ssbd"

# hadolint ignore=DL3008
RUN apt-get update \
    && apt-get install --no-install-recommends -y \
        binutils-mips-linux-gnu \
        build-essential \
        clang \
        # FIXME: overkill
        gcc-multilib \
        git \
        libcapstone-dev \
        # NOTE: used by viewText.sh
        nano \
        # FIXME: just call python3
        python-is-python3 \
        python3 \
        python3-pip \
        # NOTE: used by toP64format.sh
        xxd \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir /src \
    && git config --global --add safe.directory "*"

WORKDIR /src

ENV PATH="/src/tools:${PATH}"
