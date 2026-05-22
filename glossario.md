* **Parser:** Um algoritmo ou programa que recebe uma sequência de dados textuais de entrada, analisa essa sequência com base em um conjunto de regras gramaticais e a converte em uma estrutura de dados formal (como uma árvore sintática) para ser manipulada por um software. Ex.: RegEx
* **Web crawling:** O processo automatizado de varrer a internet ou bancos de dados online através de um "bot" (crawler) indexando informações, lendo o código das páginas e seguindo hiperlinks para mapear conteúdos de forma sistemática.
* **Web scraping:** O processo automatizado de extração focada de dados específicos contidos no código (como HTML) de páginas web, convertendo informações brutas e não estruturadas em formatos de dados limpos, estruturados e armazenáveis (como arquivos JSON, CSV ou registros em um banco de dados) para processamento ou análise posterior.
    * Geralmente crawling e scraping são usados em conjunto. O crawling mapeia, cria uma teia de conexões, e o scraping vem extraindo o que tem em cada um desses "nós" (grafos).
* **API Endpoint:** O ponto de contato digital e o URI (Uniform Resource Identifier) específico onde uma API (Application Programming Interface) recebe solicitações externas e de onde envia a resposta, marcando o local exato onde a comunicação com o servidor acontece.
* **Cadeia de Evidência (Engenharia de Requisitos):** O registro cronológico e a rastreabilidade documentada de uma funcionalidade do software, comprovando o vínculo entre a solicitação inicial do cliente/negócio, o código desenvolvido, as especificações arquiteturais e os testes de validação correspondentes.
* **Timebox Ágil:** A prática de gerenciamento de tempo que estabelece uma janela temporal estrita e fixa (um "limite máximo") para a realização de um evento, reunião ou tarefa, focando na entrega de valor e no encerramento da atividade ao término do prazo, independentemente do status de conclusão. Evita perfeccionismo extremo.
* **DevOps:** Cultura e conjunto de práticas de engenharia de software que unifica as equipes de desenvolvimento (Dev) e operação de infraestrutura (Ops). Seu foco é automatizar processos através de pipelines de Integração e Entrega Contínuas (CI/CD), garantindo que atualizações de código sejam testadas e implantadas em produção de forma rápida, segura e escalável.
* **MLOps (Machine Learning Operations):** A evolução do DevOps adaptada para os desafios da Inteligência Artificial. É a prática de orquestrar e automatizar o ciclo de vida completo de um sistema de IA em produção, rastreando, versionando e monitorando simultaneamente três pilares interdependentes: o Código, os Dados e os Modelos de ML.
* **Data Drift (Desvio de Dados):** O fenômeno em que as propriedades estatísticas, o vocabulário ou o contexto dos dados do mundo real mudam ao longo do tempo. Na engenharia de IA, o drift faz com que um modelo (mesmo com o código perfeitamente intacto) sofra degradação de performance e perca sua precisão, exigindo um retreinamento para se adaptar à nova realidade dos dados.
* **Matriz de Confusão (Confusion Matrix):** Uma tabela quadrada que correlaciona as classes reais com as classes preditas pelo modelo. É a base estrutural para o cálculo de quase todas as métricas de classificação.
    * **Componentes:**
    * **Verdadeiro Positivo (VP):** Modelo previu a classe positiva e acertou.
    * **Falso Positivo (FP):** Modelo previu a classe positiva e errou (Alarme falso).
    * **Verdadeiro Negativo (VN):** Modelo previu a classe negativa e acertou.
    * **Falso Negativo (FN):** Modelo previu a classe negativa e errou (Omissão).

* **Acurácia (Accuracy):** A fração de previsões corretas que o modelo fez sobre o total de dados avaliados. É útil quando o dataset é simétrico e balanceado, mas altamente enganosa em classes desbalanceadas.
    * **Equação:**
    $$\text{Acurácia} = \frac{VP + VN}{VP + VN + FP + FN}$$

* **Precisão (Precision):** Mede a exatidão das previsões positivas. Responde à pergunta: *"De todas as instâncias que o modelo classificou como positivas, quantas eram realmente positivas?"*. É a métrica ideal quando o custo de um Falso Positivo é crítico.
    * **Equação:**
    $$\text{Precisão} = \frac{VP}{VP + FP}$$

* **Recall:** Mede a taxa de acerto do modelo em capturar a classe de interesse. Responde à pergunta: *"De todas as instâncias que eram realmente positivas no mundo real, quantas o modelo conseguiu encontrar?"*. É vital quando omitir um caso positivo (Falso Negativo) gera consequências graves.
    * **Equação:**
    $$\text{Recall} = \frac{VP}{VP + FN}$$

* **F1-Score:** A média harmônica entre a Precisão e a Revocação. Fornece um equilíbrio único entre ambas, sendo a métrica padrão ouro para avaliar modelos de classificação operando em cenários com distribuição de classes severamente desbalanceada.
    * **Equação:**
    $$F1 = 2 \times \frac{\text{Precisão} \times \text{Recall}}{\text{Precisão} + \text{Recall}}$$

* **AUC-ROC (Área Sob a Curva ROC):** A curva ROC (*Receiver Operating Characteristic*) plota a Taxa de Verdadeiros Positivos contra a Taxa de Falsos Positivos para diferentes limiares (*thresholds*) de probabilidade. A AUC (Área Sob a Curva) varia de 0.0 a 1.0 e mede a capacidade de discriminação topológica do modelo: quão bem ele consegue separar duas classes independentemente do limiar escolhido.


* **Erro Quadrático Médio (MSE - Mean Squared Error):** Métrica e função de perda padrão para problemas de **Regressão**. Calcula a média dos quadrados das diferenças entre os valores reais ($y$) e as predições do modelo ($\hat{y}$). Por elevar o erro ao quadrado, penaliza severamente grandes desvios (*outliers*).
    * **Equação:**
    $$\text{MSE} = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2$$

* **Erro Absoluto Médio (MAE - Mean Absolute Error):** Mede a média das magnitudes absolutas dos erros em um problema de regressão, sem considerar sua direção. Diferente do MSE, o MAE trata todos os erros de forma linear, sendo mais robusto a perturbações causadas por *outliers* isolados no dataset.
    * **Equação:**
    $$\text{MAE} = \frac{1}{n} \sum_{i=1}^{n} |y_i - \hat{y}_i|$$

* **Entropia Cruzada (Cross-Entropy Loss):** A função de perda (Loss Function) mais utilizada para treinar redes neurais de classificação. Ela mede a distância matemática entre duas distribuições de probabilidade: as respostas reais (vetores binários *one-hot*) e as probabilidades geradas pela camada final (geralmente via *Softmax*). Ela pune exponencialmente previsões erradas feitas com alto nível de confiança.
    * **Equação (Binária):**
    $$\text{L}_{\text{CE}} = -\frac{1}{n} \sum_{i=1}^{n} [y_i \log(\hat{y}_i) + (1 - y_i) \log(1 - \hat{y}_i)]$$