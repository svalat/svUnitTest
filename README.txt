Pour compiler le projet :

$> mkdir build
$> cd build
$> cmake ..
$> make
$> make install

                    -----------------------

On peut changer le chemin d'installation (prefix) à l'aide de la commande :

$> cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/myprefix

                    -----------------------

Les test sont exécuté à l'aide de  :

$> make test

