# Prova-Algoritimos
 
Filtro: Tons de Cinza

Para realizar um Processamento Digital de Imagens (PDI) é necessário aplicar diversos filtros nas imagens. Um dos tipos de filtro mais conhecidos é o que transforma uma imagem colorida em tons de cinza. A análise de imagens em tons de cinza muitas vezes pode ser mais interessante para a extração de características que podem ser base para reconhecimento de padrões em imagens, como é feito em reconhecimento de doenças como câncer, identificação de faces humanas, movimentação de bandidos pelas ruas, placas de carros, digitais ou até mesmo para íris humana, por exemplo.

Existem vários processos para a transformação de imagens em tons de cinza, cada um apresentando um diferente resultado. Essa avaliação diz respeito a criação de um filtro real e funcional para transformação de imagens coloridas em tons de cinza.

Para tal, é necessário termos a representação de uma imagem colorida e de uma imagem em tons de cinza, exatamente como é feito em várias bibliotecas gráficas. Mas, como não utilizaremos uma biblioteca gráfica, criaremos as estruturas nós mesmos.

Para representação de uma imagem colorida precisaremos definir uma estrutura que representa as 3 informações básicas de uma imagem colorida no padrão mais utilizado no mundo: o RGB. Teremos uma estrutura para definir o que é um ponto da imagem: cada ponto terá 3 informações inteiras: “R”, “G” e “B”, vermelho, verde e azul, respectivamente. A junção dessas 3 informações é que gera uma cor de um ponto na tela e cada uma dessas variáveis de cores pode ter um valor entre 0 e 255. Para representar a imagem de forma que consigamos testar sem perdermos muito tempo, teremos uma matriz de apenas 3x3 desses pontos, que já foram definidos na estrutura. Ou seja, uma matriz 3x3 do tipo que foi definido na estrutura.

Para representação de uma imagem em tons de cinza é bem mais fácil. Uma imagem em tons de cinza possui apenas 1 informação por ponto, um inteiro que vai de 0 a 255. Assim, teremos apenas uma matriz 3x3 de inteiros.

Resumindo, o nosso programa pegará a imagem colorida, representada pela nossa matriz de imagem colorida, transformará em tons de cinza e gravará na imagem em tons de cinza, representada pela nossa matriz de tons de cinza.

O programa deverá possuir um menu com as seguintes opções:
    1. Preencher a imagem colorida
    2. Transformar em Tons de Cinza
    3. Imprimir as 2 imagens
    4. Sair

Esse menu deverá ser apresentado e a opção digitada pelo usuário através de um módulo (função ou procedimento). Caso a opção digitada seja diferente das opções possíveis, deve ser reapresentado o menu e solicitada nova opção para o usuário.

A opção 1 é para digitarmos os dados da imagem colorida pelo teclado. Isso é necessário, pois não carregaremos uma imagem do computador. Ou seja, nessa opção temos que criar um módulo (uma função ou um procedimento) que receba a imagem colorida por referência (como sempre é feito quanto se passa uma matriz para um módulo) e dentro desse módulo pediremos para o usuário digitar todos os dados da imagem colorida. Explicando ainda mais: o usuário digitará os valores de R, G e B de todos os pontos da imagem com valores entre 0 a 255 (deve ser feito verificação para que não tenha valores diferente desses). Como nossa imagem tem 3x3 e cada ponto tem R, G e B, o usuário preencherá 9 Rs, 9 Gs e 9 Bs. Para isso utilize laços de repetição dentro do módulo e informe para o usuário qual tipo de informação e em qual coordenada ele está digitando o valor.

A opção 2 deve chamar um módulo (função ou procedimento) que é o coração do nosso algoritmo, o módulo para transformar em tons de cinza. Esse módulo deverá receber as 2 matrizes por referência, a matriz da imagem colorida e a matriz de tons de cinza. O processo que utilizaremos é bastante simples, porém é um dos processos mais utilizados para essa transformação. Considerando que C é o valor do ponto na imagem de tons de cinza, a fórmula para transformação é a seguinte:

C = (R + G + B)/3

Ou seja, deve-se pegar os valores de R, G e B de cada ponto na imagem colorida, aplicar a fórmula (média aritmética) e o resultado colocar no ponto de mesma coordenada na imagem em tons de cinza. Para esse processo deve-se utilizar laços de repetição.

Resumindo, essa opção pegará a imagem colorida, representada pela nossa matriz de imagem colorida, transformará em tons de cinza e gravará na imagem em tons de cinza, representada pela nossa matriz de tons de cinza.

A opção 3 deve chamar um módulo que imprime as 2 imagens na tela no seguinte formato, por exemplo (com números aleatórios criados pelo professor):

*** Imagem Colorida (R,G,B) ***
5,200,3 | 2,4,130 | 2,0,1
2,2,3 | 8, 200,250 | 255,255,255
202,205,255 | 145,103,109 | 198,177,130

*** Imagem em Tons de Cinza ***
69 | 255 | 0
7 | 9 | 1
189 | 204 | 111

Caso queira imprimir mais bonito é opcional.

A opção 4 deverá encerrar o programa.

Você deverá fazer um laço de repetição para que o usuário possa digitar outra imagem ou acessar outras opções do menu, caso queira. O usuário só encerra o programa quando digitar a opção 4, qualquer outra informação fará o menu ser reimpresso e ser pedido outra opção para o usuário.

Para executar tanto a opção 2 quanto a opção 3 do menu é necessário fazer a verificação se a opção 1 já foi executada pelo menos uma vez.
