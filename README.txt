To compile the project :

$> mkdir build
$> cd build
$> cmake ..
$> make
$> make install

                    -----------------------

You can change the prefix path for installation with the command : 

$> cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/myprefix

                    -----------------------

You can run the internal unit test before installing  :

$> make test

