# Assignment 3: Pipeline Gráfico.

## Descrição
O objetivo desta atividade consiste na familiarização da estrutura do pipeline gráfico através da implementação de transformações geométricas que o compõem. 

A partir de um programa template disponibilizado pelo professor, foram feitas alterações nas matrizes Model, View e Projection, de acordo com os requisitos de cada atividade citadas a seguir:

### Atividade 1: Escala
Essa atividade consiste em modificar a escala da matriz Model. Para isso, foi aplicado um fator multiplicativo nessa matriz, de escala (x, y, z) = (0.33, 1.50, 0.00).

Após as alterações, o código ficou então da seguinte forma: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_1_code.png">

Que resultou na seguinte figura:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_1_result.png">

### Atividade 2: Translação
Essa atividade consiste em transladar a figura para direita. Para isso, foi modificada a matriz View, transladando a câmera e não o objeto, em (x, y, z) = (1.00, 0.00, 0.00). 

Após as alterações, utilizando o fator de translação , o código ficou então da seguinte forma: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_2_code.png">

Que resultou na seguinte figura:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_2_result.png">

### Atividade 3: Projeção Perspectiva
Essa atividade consiste em modificar a matriz Projection para aplicar uma distorção perspectiva. Para isso, foi utilizado uma matriz de projeção estudada em sala, mostrada na figura abaixo, onde d é a distância do centro de projeção até a origem do sistema de coordenadas da câmera.

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/projection_matrix.png">

Após as alterações, utilizando uma distância (d) de 0.5, o código ficou então da seguinte forma: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_3_code.png">

Que resultou na seguinte figura:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_3_result.png">

### Atividade 4: Posição da Câmera
Essa atividade consiste em modificar a posição da câmera, mantendo a distorção perspectiva da atividade 3. Para isso, é necessário definir os vetores do espaço da câmera, de acordo com os requisitos da atividade. Ponto para onde a câmera aponta (0.00, 0.00, 0.00), vetor up da câmera (0.00, 1.00, 0.00) e a posição da câmera (-0.10, 0.10, 0.25).

Então, é preciso obter a matriz B, que será utilizada para calcular a matriz de visualização, utilizando funções normalize e cross do glm. Então, a nova matriz View será o produto das matrizes B transposta e T.

Após as alterações, o código ficou então da seguinte forma: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_4_code.png">

Que resultou na seguinte figura:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_4_result.png">

### Atividade 5: Transformação Livre
Essa atividade consiste em modificar da maneira que quiser as matrizes Model, View e Projection, sem reutilizar das implementações feitas em atividades anteriores. 

Para o Model, foi aplicado um fator de multiplicação 0.50 em X e 0.10 em Y, o que resultou em uma imagem curta e alongada.
Para o View, um deslocamento de -1.00 em X e 1.25 em Y, o que resultou em uma imagem deslocada para esquerda e para cima.
Para o Projection, foi utilizado uma distância (d) de 1.50, o que resultou em um aumento na distorção perspectiva.

Após as alterações, o código ficou então da seguinte forma: 

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_5_code.png">

Que resultou na seguinte figura:

<img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_3/screenshots/exercise_5_result.png">

### Referências
- [OpenGL Mathematics](https://glm.g-truc.net/0.9.9/index.html)
- [Geometric Functions - GLM](https://glm.g-truc.net/0.9.4/api/a00131.html)
