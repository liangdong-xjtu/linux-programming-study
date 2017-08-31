
#!/bin/sh -x
if [ "x$1" = "x" ]; then
    cat /proc/sys/kernel/threads-max
elif [ "x$1" = "xset" ]; then
    echo
#    echo 9999 > /proc/sys/kernel/threads-max
elif [ "x$1" = "xreset" ]; then
    echo
#    echo 63691 > /proc/sys/kernel/threads-max
fi
set +x
