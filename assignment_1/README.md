# Assignment 1: Rasterização de pontos e linhas.

## Descrição
A atividade é baseada na realização de um algoritmo de rasterização de pontos e linhas, sendo necessário triângulos desenhados através de construção de arestas (linhas rasterizadas). As cores atribuidas a cada vértice formam um efeito suave ao longo da linha que conecta os mesmos através da técnica de interpolação, obtendo-se um efeito degradê caso os vértices (ou pontos extremos) tenham cores distintas. A rasterização é feita através da escrita direta na memória, utilizando um framework para simular o acesso à memória de vídeo.

Em resumo, há a implementação de 3 funções principais:

    PutPixel: Rasteriza um ponto na memória de vídeo;
    DrawLine: Função que rasteriza uma linha na tela com interpolação linear das cores dos vértices;
    DrawTriangle: Desenha as arestas de um triângulo na tela.

### Ponto de Partida
Para melhor estruturação e manipulação, o ponto é representado pela struct Pixel, composta por duas outras structs: Coordinate e Color.

A atribuição de um Pixel é feito pela função `setPixel(Coordinate coord, Color color)`, onde sua coordenada é atribuída através da chamada `setCoordinate(int x, int y)` e sua cor através da chamada `setColor(int red, int green, int blue, int alpha)`.

### PutPixel()
Essa função gera um ponto no espaço, onde sua posição é determinada pelas coordenadas (x, y) e sua cor e opacidade é determinada pelos valores RGBA.

O código abaixo define primeiramente o pixel, com sua respectiva coordenada e valores RGBA e então a função é chamada, com o pixel passado por parâmetro.

Vale lembrar que o ponto (0, 0) é definido como o canto superior esquerdo da janela.

```c
    Coordinate p1_coord = setCoordinate(100, 100);
    Color p1_color = setColor(255, 0, 0, 255);
    Pixel p1 = setPixel(p1_coord, p1_color);

    PutPixel(p1, p1_color);
```

O resultado pode ser observado na imagem abaixo:

<p align="center">
  <img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_1/screenshots/put_pixel.png">
</p>

### DrawLine()
Essa função utiliza as coordenadas de dois pontos para traçar uma reta de conexão entre elas, utilizando o algoritmo adaptado de Bresenham. Devido à finidade de pixels na tela, não é possível desenhar uma linha perfeita, então faz-se necessário o uso deste algoritmo, que toma a decisão para que o desenho seja o mais próximo do esperado. 

Com a função que desenha a reta implementada, é feito então a interpolação de cores, que funciona como um degradê, onde a cor reta altera-se suavemente ao longo da reta, iniciando de um ponto ao outro.

O código abaixo define primeiramente os vértices, com suas respectivas coordenadas e valores RGBA e então a função é chamada, com os vértices passados por parâmetro.

```c
    Coordinate p1_coord = setCoordinate(100, 100);
    Color p1_color = setColor(255, 0, 0, 255);
    Pixel p1 = setPixel(p1_coord, p1_color);

    Coordinate p2_coord = setCoordinate(300, 200);
    Color p2_color = setColor(0, 255, 0, 255);
    Pixel p2 = setPixel(p2_coord, p2_color);

    DrawLine(p1, p2);
```

Infelizmente, a função de interpolação de cores não está com os cálculos de porcentagem de distância entre os pontos corretos, então o gradiente não funciona 100% como esperado.

O resultado incompleto pode ser visto abaixo:

<p align="center">
  <img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_1/screenshots/draw_line.png">
</p>

### DrawTriangle()
Essa função realiza o desenho de um triângulo, que consite em três retas, desenhadas através da função `DrawLine()`. Os três pontos passados como parâmetro conectam-se entre si. Esses pontos são definidos através da struct Pixel e cada um possui uma cor definida.

O código abaixo define primeiramente os vértices, com suas respectivas coordenadas e valores RGBA e então a função é chamada, com os vértices passados por parâmetro.

```c
    Coordinate p1_coord = setCoordinate(100, 100);
    Color p1_color = setColor(255, 0, 0, 255);
    Pixel p1 = setPixel(p1_coord, p1_color);

    Coordinate p2_coord = setCoordinate(300, 200);
    Color p2_color = setColor(0, 255, 0, 255);
    Pixel p2 = setPixel(p2_coord, p2_color);
  
    Coordinate p3_coord = setCoordinate(200, 350);
    Color p3_color = setColor(0, 0, 255, 255);
    Pixel p3 = setPixel(p3_coord, p3_color);

    DrawLine(p1, p2);
```

É possível observar no resultado abaixo, que devido ao incorreto funcionamento da interpolação de cores, não há suavidade no degradê de cada reta:

<p align="center">
  <img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_1/screenshots/draw_triangle.png">
</p>

### Considerações Finais
Após implementação das funções citadas acima, foram criadas três funções, `getRandomColor()`, que retorna valores aleatórios para RGBA, `getRandomCoordinate()`, que retorna uma coordenada aleatória dentro do espaço disponível e `DrawFancyStar()`.
Essa função utiliza todas as funções descritas nesta atividade, com o objetivo de desenhar uma estrela de cinco vértices, definidos a partir do tamanho da janela, que possuem cores que alteram-se aleatoriamente, criando um efeito um pouco psicodélico.
Além disso, diversos pontos com coordenadas e cores aleatórias também são inseridas na tela, de forma contínua, a cada atualização da mesma.

A chamada da função é `DrawFancyStar();` e o seu resultado após um período de tempo pode ser visualizado abaixo:

<p align="center">
  <img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_1/screenshots/draw_fancy_star.png">
</p>

### Referências
- [Drawing Line Using Bresenham Algorithm](http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm)
- [Interpolação de Cores](http://letslearnbits.blogspot.com/2014/10/icgt1-interpolacao-de-cores.html)