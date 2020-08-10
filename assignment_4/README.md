# Assignment 4: Modelos de Iluminação.

## Descrição
O objetivo desta atividade consiste na familiarização dos modelos de iluminação tradicionalmente utilizados na rasterização: ambiente, difuso e especular (ou Phong).

A partir de um programa template disponibilizado pelo professor, foram feitas alterações no arquivo vertex_shader do OpenGL, onde após ser compilado e executado, exibe uma cena composta por uma malha de triângulos que representa o Utah Teapot e o modelo de iluminação ambiente: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_4/screenshots/initial_utah_teapot.png">

É importante ressaltar que o teapot encontra-se na origem, a fonte de luz pontual encontra-se na posição (-2.0, 2.0, 1.5) e a câmera em (0.0, 0.0, 1.5), com vetor up = (0.0, 1.0, 0.0) e direção (0.0, 0.0, -1.0). Todas as posições são informadas no Espaço do Universo e a configuração geométrica da cena pode ser visualizada abaixo:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_4/screenshots/scene.png">

Na imagem acima, o ponto laranja no canto superior esquerdo representa a posição da fonte de luz pontual. A pirâmide preta abaixo da imagem representa o volume de visualização da câmera, que se encontra posicionada sobre o eixo Z, no vértice do volume. O triângulo preto acima do volume de visualização representa a direção Up da câmera. O sistema de coordenadas é mão-direita, onde o eixo vermelho representa o eixo X e o verde o eixo Z.

### Atividade 1: Modelo de Reflexão Difuso
Essa atividade consiste em modificar o vertex shader, de forma a incluir o modelo difuso, além do modelo de iluminação ambiente já incluso. Para isso, foi necessário calcular o novo vetor normal N, após as trasnformações feitas pela matriz Model, bem como o vetor L que aponta do vértice para a fonte de luz.

Após as alterações, o código ficou então da seguinte forma: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_4/screenshots/exercise_1_code.png">

Que resultou na seguinte figura:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_4/screenshots/exercise_1_result.png">

### Atividade 2: Modelo de Reflexão Especular
Essa atividade consiste em modificar o vertex shader novamente, de forma a incluir também o modelo especular, além do modelo de iluminação ambiente e o modelo difuso já inclusos. Para isso, foi necessário calcular o novo vetor de reflexão R da luz L, o vetor da câmera V, que aponta do vértice em questão para a câmera e por fim calcular o modelo de reflexão especular com n = 64.

Após as alterações, o código ficou então da seguinte forma: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_4/screenshots/exercise_2_code.png">

Que resultou na seguinte figura:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_4/screenshots/exercise_2_result.png">

### Referências
- [OpenGL Mathematics](https://glm.g-truc.net/0.9.9/index.html)
- [Geometric Functions - GLM](https://glm.g-truc.net/0.9.4/api/a00131.html)
