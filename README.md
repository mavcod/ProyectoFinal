# ProyectoFinal
Proyecto final Edson-Manuel
#### Introducción
El modelo HSV (del inglés Hue, Saturation, Value – Matiz, Saturación, Valor),  define un modelo de color en términos de sus componentes. De esta forma se puede realizar la transformación para conocer los valores básicos RGB en el dominio HSV:

RGB a HSV funciones | Cono HSV
------------ | -------------
![HSV](http://www.cs.cityu.edu.hk/~howard/Teaching/CS4185-5185-2008-SemA/Group03/graph/CS5185_51414221_peoject_html_m27f8304e.gif) | ![cono](https://upload.wikimedia.org/wikipedia/commons/f/f1/HSV_cone.jpg)



Donde disponemos de 360 grados dónde se dividen los 3 colores RGB, eso da un total de 120º por color, sabiendo esto podemos recordar que el 0 es rojo RGB(1, 0, 0), 120 es verde RGB(0, 1, 0) y 240 es azul RGB(0, 0, 1). Para colores mixtos se utilizan los grados intermedios, el amarillo, RGB(1, 1, 0) está entre rojo y verde, por lo tanto 60º. Se puede observar como se sigue la secuencia de sumar 60 grados y añadir un 1 o quitar el anterior. Para el color blanco se puede poner cualquier color y saturación, siempre que se establezca el valor (de luminosidad) máximo. Asimismo, para el color negro se puede poner cualquier color y saturación, siempre que se ponga un valor de 0.

Para retornar a los valores de canales RGB se utilizan las siguientes relaciones.

![G1](https://upload.wikimedia.org/math/1/6/d/16d757c11ee0b974d219545c04e7f0a9.png)

![G2](https://upload.wikimedia.org/math/d/0/7/d075cc36613c0f0a9439f8efd1de3968.png)

![G3](https://upload.wikimedia.org/math/9/8/6/9868464d4d409a2a51d223799ce0ec22.png)

![G4](https://upload.wikimedia.org/math/c/4/4/c441e510cb02e7b48cfe805a2bf21e4f.png)

![G5](https://upload.wikimedia.org/math/6/8/8/68851b44165cb21696cbe8df8ecfc1ce.png)

![G6](https://upload.wikimedia.org/math/6/8/8/68851b44165cb21696cbe8df8ecfc1ce.png)

![G7](https://upload.wikimedia.org/math/0/9/9/099797d556b4331b641a46934348041c.png)


 
En este nuevo dominio, se puede controlar la cantidad de iluminación, sombras y componentes de color. Para el caso de las imágenes bajo el agua, se tienen imágenes con exceso de tonos azules y el ruido de la iluminación, basado en el tono azul oscuro que puede tomar una imagen el filtro propuesto busca resaltar las siluetas que contienen matices azules oscuras respecto al tono de la escena, el uso de esta técnica aún está en evaluación y formalización matemática, por lo que su divulgación debe ser cautelosa a causa que no se han detectado casos de uso donde no pueda funcionar.

