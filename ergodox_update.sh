echo "Insert LEFT ergodox in burn mode and press enter"
read LINE;
CFLAGS="-Wno-error=deprecated" make ergodox_infinity:db
sudo CFLAGS="-Wno-error=deprecated" make ergodox_infinity:db:dfu-util
echo "Sleep to allow keyboard to reconnect..."
sleep 2
setxkbmap se
echo "Insert RIGHT ergodox in burn mode and press enter"
read LINE;
CFLAGS="-Wno-error=deprecated" make ergodox_infinity:db MASTER=right
sudo CFLAGS="-Wno-error=deprecated" make ergodox_infinity:db:dfu-util MASTER=right
echo "Sleep to allow keyboard to reconnect..."
sleep 2
setxkbmap se
