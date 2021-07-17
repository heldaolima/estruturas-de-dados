#include <stdio.h>
2 #include <stdlib.h>
3 #include <string.h>
4
5 typedef struct {
6 char nome[31]; //titulo autor edicao quant
7 int idade;
8 }Elem;
9
10 typedef struct no{
11 Elem elemento;
12 struct no *proximo;
13 // struct no *anterior; lista duplamente encadeada
14 }No;
15
16 typedef struct {
17 No *inicio;
18 // No *fim lista circula
19 }ListaSimplesmenteEncadeada;
20
21 int menu()
22 {
23 int v;
24 printf(" Digite um valor de 1 para criar uma lista \n ");
25 printf("Digite um valor de 2 para saber se a lista está vazia \n ");
26 printf("Digite um valor de 3 para saber a quantidade de elementos na lista \n ");
27 printf("Digite um valor de 4 para inserir um elemento no início da lista \n ");
28 printf("Digite um valor de 5 para inserir um elemento no final da lista \n ");
29 printf("Digite um valor de 6 para imprimir a lista \n ");
30 printf("Digite um valor de 7 para saber se um elemento pertence a lista \n ");
31 printf("Digite um valor de 8 para remover um elemento no início da lista \n ");
32 printf("Digite um valor de 9 para remover um elemento no final da lista \n ");
33 printf("Digite um valor de 10 para remover um elemento da lista \n ");
34 printf("Digite um valor de 11 para sair do programa \n ");
35 scanf("%d", &v);
36 return v;
37 }
38
39 void Criar(ListaSimplesmenteEncadeada *lista){
40 lista->inicio = NULL;
41 }
42
43 int Vazia(ListaSimplesmenteEncadeada lista){
44 if (lista.inicio == NULL)
45 return 0;
46 else return 1;
47 }
48
49 int Quantidade(ListaSimplesmenteEncadeada lista){
- 1 -
/home/roberta/projects/EstruturaListaDinanmica.c
Página 2 de 8 qua 14 jul 2021 18:57:29
50 No *atual;
51 int qtde = 0;
52
53 for (atual = lista.inicio; atual != NULL; atual = atual->proximo)
54 qtde++;
55 return qtde;
56
57 // atual= lista.inicio;
58 // while (atual != NULL){
59 // qtde++;
60 // atual= atual->proximo;
61 // }
62
63 // if (lista == Null)
64 // return 0;
65 // else{
66 // return 1+Quantidade(lista->proximo)
67 // }
68
69 // [1,2,3,4] head=1 tail=[2,3,4]
70 // 1 + Quantidade([2,3,4]) =1+3
71
72 // [2,3,4] head=2 tail=[3,4]
73 // 1 + Quantidade([3,4]) = 1+2
74
75 // [3,4] head=3 tail=[4]
76 // 1 + Quantidade([4]) == 1+1
77
78 // [4] head=4 tail=[]
79 // 1 + Quantidade([]) == 1+0
80
81 // []
82 // 0
83
84 }
85
86 int Pesquisa(ListaSimplesmenteEncadeada lista, char *nome){
87 No *atual = lista.inicio;
88
89 while (atual != NULL){
90 if (strcmp(atual->elemento.nome, nome) == 0)
91 return 0;
92 atual = atual->proximo;
93 }
94 return 1;
95 }
96
97 int InsereInicio(ListaSimplesmenteEncadeada *lista, Elem novoElemento){
98 No *novo;
- 2 -
/home/roberta/projects/EstruturaListaDinanmica.c
Página 3 de 8 qua 14 jul 2021 18:57:29
99 int v;
100
101 // if ((novo = malloc(sizeof(No)))==NULL)
102 v = Pesquisa(*lista, novoElemento.nome);
103 if (v ==0){
104 printf("O elemento %s ja existe \n", novoElemento.nome);
105 return 1;
106 }
107 else {
108 novo = malloc(sizeof(No));
109 if (novo == NULL)
110 return 1;
111 novo->elemento = novoElemento;
112 novo->proximo = lista->inicio;
113 lista->inicio = novo;
114 return 0;
115 }
116 }
117
118 int InsereFim(ListaSimplesmenteEncadeada *lista, Elem novoElemento){
119 No *atual, *novo;
120 int v = 0;
121
122 v = Vazia(*lista);
123 if (v==0)
124 return InsereInicio(lista, novoElemento);
125
126 atual = lista->inicio;
127 while (atual->proximo != NULL)
128 atual = atual->proximo;
129 novo = malloc(sizeof(No));
130 if (novo == NULL)
131 return 1;
132
133 atual->proximo = novo;
134 novo->proximo = NULL;
135 novo->elemento = novoElemento;
136
137 return 0;
138 }
139
140 void Imprime(ListaSimplesmenteEncadeada lista){
141 No *atual;
142 for (atual = lista.inicio; atual != NULL; atual = atual->proximo){
143 printf("Nome: %s - ", atual->elemento.nome);
144 printf("Idade: %d\n", atual->elemento.idade);
145 }
146 }
147
- 3 -
/home/roberta/projects/EstruturaListaDinanmica.c
Página 4 de 8 qua 14 jul 2021 18:57:29
148 int RemoveInicio(ListaSimplesmenteEncadeada *lista, Elem *elem){
149 No *atual;
150 int v;
151
152 v = Vazia(*lista);
153 if (v == 0) return 1;
154
155 atual = lista->inicio; // aponta para head
156 lista->inicio = atual->proximo; // inicio = tail
157 *elem = atual->elemento; // endereço da head(1)
158 free(atual); // no que contem a head(1) deixa de
referencia a lista
159
160 return 0;
161
162 // []
163 // [1,2,3,4] head=1 tail=[2,3,4]
164 //
165
166 }
167
168 int RemoveFim(ListaSimplesmenteEncadeada *lista, Elem *elem){
169 No *atual, *anterior = NULL;
170 int v;
171
172 v = Vazia(*lista);
173 if (v == 0) return 1;
174
175 atual = lista->inicio;
176 while (atual->proximo != NULL){
177 anterior = atual;
178 atual = atual->proximo;
179 }
180
181 if (anterior == NULL)
182 return RemoveInicio(lista, elem);
183
184 *elem = atual->elemento;
185 anterior->proximo = atual->proximo; //NULL
186 free(atual);
187 return 0;
188 }
189
190 int Remove(ListaSimplesmenteEncadeada *lista, char *nome, Elem *elem){
191 No *anterior, *atual;
192 int v;
193
194 v = Vazia(*lista);
195 if (v == 0)
- 4 -
/home/roberta/projects/EstruturaListaDinanmica.c
Página 5 de 8 qua 14 jul 2021 18:57:29
196 return 1;
197
198 anterior = NULL;
199 atual = lista->inicio;
200 while (atual != NULL){
201 if (strcmp(atual->elemento.nome, nome) == 0){
202 if (anterior == NULL)
203 return RemoveInicio(lista, elem);
204
205 anterior->proximo = atual->proximo;
206 *elem = atual->elemento;
207
208 free(atual);
209 return 0;
210 }
211 anterior = atual;
212 atual = atual->proximo;
213 }
214 return 1;
215 }
216
217
218 int RemoveTodas(ListaSimplesmenteEncadeada *lista, char *nome, Elem *elem){
219 No *anterior, *atual;
220 int v;
221
222 v = Vazia(*lista);
223 if (v == 0)
224 return 1;
225
226 anterior = NULL;
227 atual = lista->inicio;
228 while (atual != NULL){
229 if (strcmp(atual->elemento.nome, nome) == 0){
230 if (anterior == NULL)
231 return RemoveInicio(lista, elem);
232
233 anterior->proximo = atual->proximo;
234 *elem = atual->elemento;
235
236 free(atual);
237
238 }
239 anterior = atual;
240 atual = atual->proximo;
241 }
242 return 1;
243 }
244
- 5 -
/home/roberta/projects/EstruturaListaDinanmica.c
Página 6 de 8 qua 14 jul 2021 18:57:29
245
246 int main(void)
247 {
248 int valor;
249 Elem e;
250 ListaSimplesmenteEncadeada l;
251
252 valor = menu();
253
254 while (valor != 11){
255 switch( valor )
256 {
257 case 1 :
258 // void Criar(ListaSimplesmenteEncadeada *lista)
259 Criar(&l);
260 break;
261
262 case 2 :
263 // int Vazia(ListaSimplesmenteEncadeada lista)
264 valor = Vazia(l);
265 printf("************************************* \n");
266 if (valor == 0)
267 printf("A lista esta vazia \n");
268 else {
269 printf("A lista não está vazia \n");
270 }
271 printf("************************************* \n");
272 break;
273
274 case 3 :
275 // int Quantidade(ListaSimplesmenteEncadeada lista)
276 printf("************************************* \n");
277 printf ("A quantidade de elementos na lista é %d \n ", Quantidade(l));
278 printf("************************************* \n");
279 break;
280
281 case 4 :
282 // int InsereInicio(ListaSimplesmenteEncadeada *lista, Elem novoElemento)
283 printf("************************************* \n");
284 printf("Digite o nome do aluno \n ");
285 scanf("%s",e.nome);
286 printf("Digite a idade do aluno \n ");
287 scanf("%d",&e.idade);
288 printf("************************************* \n");
289 valor = InsereInicio(&l,e);
290 printf("************************************* \n");
291 if (valor == 0)
292 printf("O elemento foi inserido \n");
293 else {
- 6 -
/home/roberta/projects/EstruturaListaDinanmica.c
Página 7 de 8 qua 14 jul 2021 18:57:29
294 printf("O elemento não foi inserido \n");
295 }
296 printf("************************************* \n");
297 break;
298
299 case 5 :
300 // int InsereFim(ListaSimplesmenteEncadeada *lista, Elem novoElemento)
301 printf("************************************* \n");
302 printf("Digite o nome do aluno \n ");
303 scanf("%s",e.nome);
304 printf("Digite a idade do aluno \n ");
305 scanf("%d",&e.idade);
306 printf("************************************* \n");
307 valor = InsereFim(&l,e);
308 printf("************************************* \n");
309 if (valor == 0)
310 printf("O elemento foi inserido \n");
311 else {
312 printf("O elemento não foi inserido \n");
313 }
314 printf("************************************* \n");
315 break;
316
317 case 6 :
318 // void Imprime(ListaSimplesmenteEncadeada lista)
319 printf("************************************* \n");
320 Imprime(l);
321 printf("************************************* \n");
322 break;
323
324 case 7 :
325 // int Pesquisa(ListaSimplesmenteEncadeada lista, char *nome)
326 printf("************************************* \n");
327 printf("Digite o nome do aluno \n ");
328 scanf("%s",e.nome);
329 printf("************************************* \n");
330 valor = Pesquisa(l,e.nome);
331 printf("************************************* \n");
332 if (valor == 0)
333 printf("O elemento pertence a lista \n");
334 else {
335 printf("O elemento não pertence a lista \n");
336 }
337 printf("************************************* \n");
338 break;
339
340 case 8 :
341 // int RemoveInicio(ListaSimplesmenteEncadeada *lista, Elem *elem)
342 printf("************************************* \n");
- 7 -
/home/roberta/projects/EstruturaListaDinanmica.c
Página 8 de 8 qua 14 jul 2021 18:57:29
343 valor = RemoveInicio(&l,&e);
344 printf("************************************* \n");
345 if (valor == 0)
346 printf("O elemento %s foi removido da lista \n", e.nome);
347 else {
348 printf("O elemento %s não foi removido da lista \n", e.nome);
349 }
350 printf("************************************* \n");
351 break;
352
353 case 9 :
354 // int RemoveFim(ListaSimplesmenteEncadeada *lista, Elem *elem)
355 printf("************************************* \n");
356 valor = RemoveFim(&l,&e);
357 printf("************************************* \n");
358 if (valor == 0)
359 printf("O elemento %s foi removido da lista \n", e.nome);
360 else {
361 printf("O elemento %s não foi removido da lista \n", e.nome);
362 }
363 printf("************************************* \n");
364 break;
365
366 case 10 :
367 // int Remove(ListaSimplesmenteEncadeada *lista, char *nome, Elem *elem)
368 printf("************************************* \n");
369 printf("Digite o nome do aluno \n ");
 scanf("%s",e.nome);
371 valor = RemoveTodas(&l,e.nome,&e);
372 printf("************************************* \n");
373 if (valor == 0)
374 printf("O elemento %s foi removido da lista \n", e.nome);
375 else {
 printf("O elemento %s não foi removido da lista \n", e.nome);
 }
 printf("************************************* \n");
 break;

 default :
 printf ("Valor invalido!\n");
 }
valor = menu();
}
printf("FIM");
 return 0;
 }