#!/usr/bin/env python
# coding: utf-8

# In[20]:


import matplotlib.pyplot as plt
import pandas as pd

results = pd.read_csv("results2.csv")

num_threads = results["num_threads"]
threads_time = results["thread_time"]
overall_time = results["overall_time"]
processing_time = results["process_time"]

plt.figure(figsize=(10, 5))
plt.subplot(1, 3, 1)
plt.bar(num_threads, threads_time, color='blue')
plt.xlabel('Número de Threads')
plt.ylabel('Tempo de Execução das Threads')
plt.title('Tempo de Execução das Threads')

plt.subplot(1, 3, 2)
plt.bar(num_threads, processing_time, color='green')
plt.xlabel('Número de Threads')
plt.ylabel('Tempo de Processamento')
plt.title('Tempo de Processamento')

plt.subplot(1, 3, 3)
plt.bar(num_threads, overall_time, color='red')
plt.xlabel('Número de Threads')
plt.ylabel('Tempo Total de Execução')
plt.title('Tempo Total de Execução')

plt.tight_layout()
plt.show()

