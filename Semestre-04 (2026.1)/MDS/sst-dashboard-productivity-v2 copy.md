# SST — Dashboard de Produtividade (ContraDito)

Este documento serve como a **Single Source of Truth (SST)** para o subsistema de coleta de métricas e visualização de produtividade do projeto ContraDito. Ele define os contratos, os princípios de engenharia e a estrutura técnica para a automação de métricas.

## 1. Visão Geral do Projeto
O **ContraDito** é um portal de transparência política que utiliza Inteligência Artificial (LLMs e RAG) para cruzar discursos parlamentares com votações nominais, gerando um Score de Coerência. Este dashboard visa fornecer visibilidade técnica sobre a evolução da engenharia do projeto, garantindo que o desenvolvimento seja orientado a dados.

## 2. Princípios Fundamentais (Constituição)
* **Autonomia e CI/CD:** A coleta e publicação de dados devem ser 100% automatizadas via GitHub Actions, sem intervenção humana manual.
* **Verificabilidade Pública:** Toda métrica deve ser derivada de eventos públicos (Git logs, GitHub API), permitindo auditoria externa por qualquer membro da comunidade acadêmica.
* **Design-First (SDD):** Nenhuma alteração no código de coleta ou visualização deve ser feita sem a atualização prévia desta especificação. A SST lidera a implementação.
* **Eficiência de Recursos:** Utilização estrita de recursos nativos do ecossistema GitHub (Pages e Actions) para manter custo zero e baixa latência, sem dependências de infraestrutura externa.

## 3. Arquitetura e Convenções Técnicas

### 3.1. Estrutura de Arquivos Obrigatória
```text
.github/workflows/metrics.yml       # Workflow de coleta semanal
docs/productivity/
├── collect_metrics.py               # Script Python coletor
├── requirements.txt                 # Dependências (PyGithub)
├── metrics.json                     # Dados (gerado pelo CI)
└── index.html                       # Dashboard estático
```

### 3.2. Stack Tecnológico
| Componente | Tecnologia/Padrão |
| :--- | :--- |
| **Coleta de Dados** | Python 3.11+ utilizando a biblioteca `PyGithub`. Depende de `GITHUB_TOKEN` e `GITHUB_REPOSITORY`. |
| **Contrato de Dados (SST)** | JSON estruturado (`metrics.json`) servido na mesma origem (sem CORS issues). |
| **Visualização** | HTML5 Estático + D3.js v7 (CDN) + TailwindCSS (CDN). Responsivo (Mobile-first). Zero build step. |
| **Hospedagem e Deploy** | GitHub Pages servindo a pasta `docs/productivity/`. |
| **Automação (CI)** | GitHub Actions (`actions/checkout@v4`, `actions/setup-python@v5`). Cron semanal e dispatch manual. Permissão `contents: write`. |
| **Paleta Institucional (UnB)** | Azul Escuro (#003366), Verde (#005C37), Azul Médio (#004A8C), Dourado (#BFA630). |

## 4. Definição da Estrutura de Dados (Contrato)

O script `collect_metrics.py` deve ser idempotente (regerar o JSON do zero a cada execução) e produzir estritamente o formato abaixo. O frontend `index.html` usará exclusivamente estes dados para bindar os gráficos.

### 4.1. Schema Oficial (`metrics.json`)
```json
{
  "generated_at": "2026-05-11T23:00:00Z",
  "repository": "unb-mds/2026.1-ContraDito",
  
  "issues_per_week": [
    { "week": "2026-W18", "opened": 5, "closed": 3 },
    { "week": "2026-W19", "opened": 8, "closed": 6 }
  ],
  "commit_message_histogram": [
    { "range": "0-20", "count": 12 },
    { "range": "21-50", "count": 30 },
    { "range": "51-100", "count": 45 },
    { "range": "101-200", "count": 20 },
    { "range": "200+", "count": 5 }
  ],
  "coauthors_per_week": [
    { "week": "2026-W18", "count": 4 },
    { "week": "2026-W19", "count": 6 }
  ],
  "commit_heatmap": [
    { "day": 0, "hour": 10, "count": 8 },
    { "day": 3, "hour": 15, "count": 12 },
    { "day": 6, "hour": 22, "count": 2 }
  ],
  "top_committers": [
    { "username": "luiz", "name": "Luiz", "commits": 45 },
    { "username": "joao", "name": "João", "commits": 42 }
  ],
  "top_pr_authors": [
    { "username": "henrique", "name": "Henrique", "prs_opened": 15 }
  ],
  "top_issue_contributors": [
    { "username": "gabriel", "name": "Gabriel", "opened": 10, "closed": 8, "total": 18 }
  ],
  "pull_requests_time_to_merge": [
    { "week": "2026-W18", "avg_hours": 14.5 },
    { "week": "2026-W19", "avg_hours": 9.2 }
  ],
  "code_review_matrix": [
    { "reviewer": "luiz", "author": "joao", "approved_prs": 5 },
    { "reviewer": "henrique", "author": "gabriel", "approved_prs": 3 }
  ],
  "lead_time_issues_by_label": [
    { "label": "bug", "avg_days_to_close": 2.1 },
    { "label": "enhancement", "avg_days_to_close": 5.4 }
  ],
  "code_churn_per_week": [
    { "week": "2026-W18", "additions": 1200, "deletions": 450, "modifications": 300 }
  ],
  "commit_types_distribution": [
    { "type": "feat", "count": 45 },
    { "type": "fix", "count": 12 },
    { "type": "docs", "count": 8 },
    { "type": "chore", "count": 5 }
  ],
  "bus_factor_risk": [
    { "module": "backend/api", "top_contributor": "luiz", "ownership_percentage": 85 },
    { "module": "frontend/ui", "top_contributor": "joao", "ownership_percentage": 60 }
  ]
}
```

## 5. Critérios de Aceite (Pronto Quando)
* **Script Coletor:** Roda localmente com token válido e gera o schema acima.
* **Workflow CI:** Usa `contents: write` para commitar o JSON atualizado na branch, roda no cron e manual.
* **Front-end:** Renderiza os componentes visuais consumindo o JSON via `fetch` relativo, sem erros de console.

## 6. Limitações e Fora de Escopo
* Não serão coletadas métricas de repositórios externos ao ContraDito.
* Não será implementada persistência em banco de dados externo (Postgres/Supabase) para manter a simplicidade estática.
* A autenticação é gerida exclusivamente via segredos nativos do GitHub.
