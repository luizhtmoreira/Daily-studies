---
name: study-log
description: Generate individual daily study log files in Markdown for each subject studied. Use when the user wants to register, create, write, or update a study log, study diary, or daily study record — including mentions of "log de estudo", "diário de estudos", "registrar estudos", "gera o log", or any request to document a study session. Can automatically extract subject, progress, notes, and difficulties from the current conversation history without the user filling fields manually.
---

# Study Log

## Repository structure

```
Daily-studies/
└── Semestre-04 (2026.1)/
    ├── EDA 2/
    │   └── YYYY-MM-DD-log.md
    ├── MDS/
    │   └── YYYY-MM-DD-log.md
    ├── SBD 1/
    │   └── YYYY-MM-DD-log.md
    ├── TED 1/
    │   └── YYYY-MM-DD-log.md
    ├── TEMA (Visão Computacional)/
    │   └── YYYY-MM-DD-log.md
    └── Tutoria C3/
        └── YYYY-MM-DD-log.md
```

One file per subject per day. Never combine subjects in the same file.

## Known subjects (Semestre-04 2026.1)

- EDA 2
- MDS
- SBD 1
- TED 1
- TEMA (Visão Computacional)
- Tutoria C3

## Required fields (per subject log)

- **Materia** — must match one of the known subjects above
- **Tempo de estudo** — duration (e.g. "1h30min")
- **Metas do dia** — what was planned
- **Progresso** — what was actually accomplished

## Optional fields

- **Resumo e anotacoes** — key notes, concepts, formulas from the session
- **Dificuldades encontradas** — blockers, doubts, topics to revisit

## Log template

```md
# Log de Estudo — {Materia} — {DD/MM/AAAA}

## Tempo de Estudo
{duration}

## Metas do Dia
- [ ] {goal 1}
- [ ] {goal 2}

## Progresso
{what was accomplished — reference which goals were completed}

## Resumo e Anotacoes
{key concepts, formulas, ideas, or summaries from the session}

## Dificuldades Encontradas
{blockers, doubts, topics to revisit — or "Nenhuma" if none}

---
Sessao registrada em {HH:MM}
```

## Workflows

### A) From conversation history (preferred)

Use this when the user invokes the skill at the end of a study session with a LLM (e.g. "gera o log de hoje", "fecha o log").

1. Read the full conversation history
2. Infer each field automatically:
   - **Materia** — from the overall topic of the conversation; match to the known subjects list
   - **Metas do dia** — what the user asked to study or cover at the start
   - **Progresso** — what was effectively covered, explained, or solved during the session
   - **Resumo e anotacoes** — key concepts explained, formulas derived, exercises solved, code written
   - **Dificuldades** — repeated questions, corrections made, points where the user struggled or asked for clarification
3. Ask only for what cannot be inferred — typically just **Tempo de estudo**
4. Present the inferred fields for confirmation before generating: "Inferi os seguintes dados — confirma ou corrige:"
5. Generate one `.md` file per subject identified and present all files

### B) Manual entry

Use this when the user provides data explicitly without a conversation to read from.

1. Check if all required fields are present
2. Ask once for everything missing
3. Generate one `.md` file per subject and present all files

## Rules

- **One file per subject** — never merge subjects into a single file
- Mark completed goals with `[x]` instead of `[ ]` when the user confirms completion
- Keep "Dificuldades Encontradas" even when empty — use "Nenhuma" as placeholder
- Never use emojis anywhere in the generated log file
- Never invent content — if inference is uncertain, ask
- Always confirm inferred fields before writing the file
- Always use Brazilian Portuguese for labels
- Dates: `DD/MM/AAAA` in the heading, `YYYY-MM-DD` in the filename