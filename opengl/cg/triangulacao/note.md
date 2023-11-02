# Anotações sobre aula de texturas

Triangulação + Meshes.

Existem varios algoritmos de triangulação maximal para o mesmo conjunto de pontos.

## Algoritmo Incremental

Simples - Inicia-se com 3 primeiros vértices, e vai escolhendo mais um vértice por vez para formar outro triangulo.

## Modelagem de Terrenos

Cada ponto é representado por uma tripla `(x, y, z)`. `X` e `Y` sao a posição geográfica, e `Z` é a altura. Fazer a triangulação no plano `X Y` primeiro e depois adicionar a coordenada `Z`.

Maximar o menor angulo de cada aresta, para uniformizar superfícies.

## Triangulação de Delaunay

### Regra da Ordem Lexicográfica Crescente

Ordenar os angulos de forma crescente das arestas. Alterar a aresta que ta separando a forma, e ordenar novamente. Escolher a ordem que tem os maiores angulos iniciais, pois é a melhor triangulação. **Aresta ilegal quando nao está na sua melhor triangulação**. Se uma superficie so possui triangulações legais, temos uma Triangulação de Delaunay.

- Ineficiente, envolve ordenação.

### Teste do círculo

Usar os três vértices do triangulo para gerar um círculo. Se o vertice oposto a aresta compartilhada ficar **fora do circulo**, é uma aresta legal. Caso seja ilegal, flipar aresta.

- É mais rapido pois de faz o teste usando determinantes.

Lista dos angulos da triangulação em ordem crescente - 

