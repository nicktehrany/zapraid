source ../common.sh

for size in 100 200 300 400 500 600 700 800 900 1000;
do
  # Repeat reboot procedure (recover the system states)
  for repeat in 0 1 2 3 4;
  do
    sudo LD_LIBRARY_PATH=$LD_LIBRARY_PATH stdbuf -oL ./src/app -n 0 -m 2 -s ${size} -c 1
    sudo LD_LIBRARY_PATH=$LD_LIBRARY_PATH stdbuf -oL ./src/app -n 1 -m 2 -s ${size} -c 0 > reboot_${size}_${repeat}
  done

  # Repeat rebuild procedure
  sudo LD_LIBRARY_PATH=$LD_LIBRARY_PATH stdbuf -oL ./src/app -n 0 -m 2 -s ${size} -c 0
  for repeat in 0 1 2 3 4;
  do
    sudo LD_LIBRARY_PATH=$LD_LIBRARY_PATH stdbuf -oL ./src/app -n 2 -m 2 -s ${size} -c 0 > rebuild_${size}_${repeat}
  done
done
