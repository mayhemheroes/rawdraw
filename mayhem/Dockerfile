FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y xorg-dev libxinerama-dev libxext-dev mesa-common-dev libglu1-mesa-dev

COPY . /repo
WORKDIR /repo
RUN make -j8 tools/single_file_creator
RUN clang++ /repo/mayhem/fuzz_CNFGGetTextExtents.cpp -fsanitize=fuzzer,address -I /repo/ -lm -lX11 -o /fuzz

FROM ubuntu:20.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y xorg-dev
COPY --from=builder /repo/tools/single_file_creator /
COPY --from=builder /fuzz /fuzz_CNFGGetTextExtents
