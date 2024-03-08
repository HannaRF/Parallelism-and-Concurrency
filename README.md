# Exercício 1: Paralelismo através de _threads_
![image](https://github.com/HannaRF/Scalable-Computing/assets/85463854/ebb315de-4723-43fd-9d46-af47f9b6d331)

### Integrantes do grupo

- Hanna Rodrigues
- Yonathan Rabinovici
- Rian Freitas

### Requerimentos
g++ == 11.3.0
Python == 3.10.6

### Instruções de uso
- Primeiramente, rode o _script_ em python `gerar_texto.py`. Ele pegará o arquivo `shakespeare.txt` e multiplicará o conteúdo do texto em 300 vezes, a fim de criar uma quantidade massiva de dados para nosso experimento.
- Depois, compile o códigio `paralelismo.cpp` para criar o experimento. No terminal, será mostrado os resultados para cada número de _threads_, de 1 a 100, sequencialmente.

### Resultados
Os resultados do serão disponibilizados no formato CSV (comma separated values), os quais serão explicados, *em ordem*, a seguir:
- *num_threads*: número de _threads_ utilizadas para a contagem de palavras.
- *block_size*: tamanho do bloco a ser processado pela _threads_, calculando dividino o tamanho da _string_ do texto pelo número de _threads_.
- *process_time*: tempo, em milisegundos, para a leitura e quebra do texto em blocos.
- *thread_time*: tempo, em milisegundos, que as _threads_ levaram para a contagem de palavras.
- *overall_time*: tempo, em milisegundos, de execução de todo o experimento.
- *count_hate*: número de palavras "hate" escritas no texto.
- *count_love*: número de palavras "love" escritas no texto.
- *most_common*: dentre das duas palavras, "love" e "hate", qual delas foi a mais frequente no texto.

*Exercício para a matéria de Computação Escalável, da Escola de Matemática Aplicada (EMAp).*
