# Debian/Ubuntu

If you are using Debian or Ubuntu, you can install the necessary packages using the following command:

```bash
sudo apt install libsdl2-dev libsdl-net1.2-dev libsdl1.2-compat-dev
```

```bash
make
make install
/usr/games/starvoyager
```

## Debugging

Run with local data.

```bash
export STARVOYAGER_DATA=./data && ./starvoyager
```

Make and run.

```bash
make && export STARVOYAGER_DATA=./data && ./starvoyager
```

*Note*: I'm in WSLv2 running Ubuntu 24.04 LTS so I installed the "gedit" packages to get my WSLg installed for the GUI application to work.
