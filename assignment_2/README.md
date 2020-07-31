# Assignment 2: Compilação e Execução do OpenGL Moderno.

## Descrição
A atividade é baseada em configurar e testar o ambiente de desenvolvimento em OpenGL 3.3. Para tal, foi disponibilizado um código para ser compilado e executado. 

### Desenvolvimento
Ao tentar simplesmente executar o código disponibilizado no sistema operacional macOS, ele acusa o seguinte erro:

<p align="center">
  <img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_2/screenshots/error_1.png">
</p>

Isso ocorre porque os headers para o GLUT e OpenGL são diferentes no macOS. Para resolver esse problema, foi necessário mudar alguns parâmetros no Makefile, assim como no assignment_1. Após alterar o Makefile, foi possível compilar e executar o código. Porém, a janela não exibiu nada, como pode ser visto na imagem abaixo:

<p align="center">
  <img src="https://github.com/luanbrl/computer-graphics/blob/master/assignment_2/screenshots/error_2.png">
</p>

Após diversas tentativas, foi decidido mudar o ambiente de desenvolvimento para uma máquina virtual com um diferente sistema operacional, o Linux. Com a máquina virtual devidamente configurada, a simples compilação retornou o seguinte erro:

```c
    error: GLSL 3.30 is not supported. Supported versions are: 1.10, 1.20, 1.30, 1.40, 1.00 ES, and 3.00 ES
```

Para resolver este problema, bastou executar o seguinte comando:

```c
    export MESA_GL_VERSION_OVERRIDE=3.0
```

O código então foi compilado e executado sem erros e warnings.