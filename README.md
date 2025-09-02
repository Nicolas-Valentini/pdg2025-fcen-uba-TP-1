\*\* pdg2025-fcen-uba-TP-1 \*\*
\*\* 2025 Procesamiento de Geometría Digital (Digital Geometry Processing) \*\*

Tarea 1

Prueba clone bien hola

0. Primero, configure su entorno de desarrollo.
1. Descargue el archivo **data-A1.zip** del sitio web del curso
   y descomprímalo en su computadora. No lo descomprima en este
   directorio, llamado DGP2025-A1, ya que de lo contrario, Git intentará
   guardar los archivos de datos grandes en su repositorio Git y podría
   fallar debido a los límites de tamaño. Es bastante difícil solucionar
   este problema una vez que lo haya hecho.
2. En este directorio, DGP2025-A1, además de este archivo README,
   debería encontrar los siguientes subdirectorios:

\*\* assets, forms, qt y src \*\*

Los subdirectorios assets, forms y qt contienen archivos que no debe
modificar por el momento. Volveremos a estos subdirectorios más
adelante.

Además, debe crear los siguientes dos subdirectorios:

\*\* bin \*\* y \*\* build \*\*

que deben estar vacíos. Los procesos de compilación llenarán estos dos
subdirectorios. Siempre puede eliminar el contenido de estos
subdirectorios y reiniciar el proceso de compilación.

Al usar CMAKE para generar archivos de proyecto para el programa
dgpTest de línea de comandos, encontrará estos archivos en el
directorio de compilación.  Al crear correctamente el objetivo INSTALL
con CMAKE, debería encontrar el ejecutable de línea de comandos
dgpTest en el directorio bin.

Al usar Qt Creator para compilar la aplicación interactiva DGP2025-A1,
qmake creará un nuevo directorio de compilación con un nombre más
largo. Este nuevo directorio se puede eliminar con todo su contenido
para reiniciar el proceso de compilación de Qt. También debería
encontrar el ejecutable interactivo en el directorio de
compilación.

El subdirectorio **src** contiene los siguientes subdirectorios:

\*\* core, io, test, util, wrl \*\* y \*\* gui \*\*

El directorio src y todos estos subdirectorios, excepto gui, también
contienen el archivo CMakeLists.txt, utilizado por CMAKE.

El subdirectorio qt top mencionado anteriormente contiene los
siguientes archivos:

DGP2025-A1.pro
DGP2025-A1.pri

utilizados por qmake. No modifique estos archivos a menos que añada
nuevos archivos a la jerarquía.

En la Tarea 1, su trabajo se limitará a los siguientes archivos:

src/gui/GuiStrings.hpp
src/core/Faces.hpp
src/core/Faces.cpp
src/io/LoaderStl.hpp
src/io/LoaderStl.cpp
src/io/SaverStl.hpp
src/io/SaverStl.cpp

3. Antes de compilar la aplicación por primera vez, edite el archivo
   src/gui/GuiStrings.hpp

En mi versión, este archivo contiene la definición de las siguientes cadenas:

\#define STUDENT\_NAME "Gabriel Taubin"

Reemplace mi nombre por el suyo en la última cadena y guarde el archivo.

4. Ejecute CMAKE o Qt Creator para crear los archivos de proyecto de
   las aplicaciones y asegúrese de que se compilen correctamente.
5. Verifique que pueda cargar y visualizar los archivos \*.wrl del
   directorio data-A1 mediante el botón de menú ARCHIVO->Cargar.
6. Mediante el botón de menú ARCHIVO-Guardar, guarde los archivos con
   diferentes nombres \*.wrl y verifique que pueda recargar los archivos
   creados mediante el botón ARCHIVO->Cargar.
7. Implemente la clase core/Faces. Para ello, edite los dos archivos
   siguientes:

core/Faces.hpp
core/Faces.cpp

8. Implemente la clase io/SaverStl para guardar mallas de triángulos
   en formato ASCII STL. Utilice la clase Faces en su
   implementación. Para ello, debe editar los dos archivos siguientes:

io/SaverStl.hpp
io/SaverStl.cpp

Lea los comentarios de los archivos para obtener más instrucciones.

9. Pruebe su implementación cargando el archivo "tetra1npf.wrl" y
   guardándolo como "tetra1npf.stl". Si usa Mac, puede verificar que haya
   creado el archivo correcto en Finder. De lo contrario, instale la
   aplicación MeshLab u otro visor/editor de mallas poligonales.
10. Implemente la clase io/LoaderStl para leer archivos STL
    ASCII. Para ello, debe editar los dos archivos siguientes:

io/LoaderStl.hpp
io/LoaderStl.cpp

11. Pruebe su implementación cargando el archivo "tetra1npf.stl" que
    creó en el paso anterior. Guarda el archivo resultante de nuevo en
    formato STL y WRL, y verifica que puedas recargar los archivos
    generados.
12. Repite los pasos 9 y 10 con el archivo "bunny-mesh-npf.wrl".
13. Descarga algunos archivos STL ASCII de internet, verifica que
    puedas cargarlos y guárdalos tanto en formato STL como WRL.
14. Usa Git y envía tu trabajo antes de la fecha límite.
    a) Localiza y elimina los archivos temporales creados por tu editor.
    b) Elimina el contenido de los subdirectorios superiores bin y build.
    c) Elimina el archivo qt/DGP2025-A1.pro.user creado por QtCreator.
    d) Elimina el directorio principal de compilación creado por QtCreator.
    e) Confirma todos los cambios.
    f) Sube tu confirmación al repositorio de GitHub.
