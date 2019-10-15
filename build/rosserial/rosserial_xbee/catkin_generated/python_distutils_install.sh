#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/alexj/ROS/ros_personal/src/rosserial/rosserial_xbee"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/alexj/ROS/ros_personal/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/alexj/ROS/ros_personal/install/lib/python2.7/dist-packages:/home/alexj/ROS/ros_personal/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/alexj/ROS/ros_personal/build" \
    "/usr/bin/python2" \
    "/home/alexj/ROS/ros_personal/src/rosserial/rosserial_xbee/setup.py" \
    build --build-base "/home/alexj/ROS/ros_personal/build/rosserial/rosserial_xbee" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/alexj/ROS/ros_personal/install" --install-scripts="/home/alexj/ROS/ros_personal/install/bin"
