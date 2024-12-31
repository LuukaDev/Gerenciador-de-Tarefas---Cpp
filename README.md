# Gerenciador-de-Tarefas---Cpp

# Documentação do Gerenciador de Tarefas

## Visão Geral

O Gerenciador de Tarefas é uma aplicação de console escrita em C++ que permite aos usuários gerenciar suas tarefas de forma simples. Ele utiliza arquivos de texto para armazenar as informações e fornece funcionalidades para adicionar, exibir, pesquisar, deletar e atualizar tarefas.

### Funcionalidades Principais:

- Adicionar novas tarefas.
- Exibir todas as tarefas.
- Pesquisar uma tarefa por ID.
- Deletar uma tarefa existente.
- Atualizar a descrição de uma tarefa.

---

## Estrutura do Código

### Estrutura `Tarefa`

A estrutura `Tarefa` representa uma tarefa individual e possui os seguintes campos:

- `Id` (int): Identificador único da tarefa.
- `Descricao` (string): Descrição textual da tarefa.

### Declaração de Funções

O programa é composto por várias funções que implementam as funcionalidades principais:

- `void Banner()`: Exibe um cabeçalho estilizado.
- `void AdicionarTarefa()`: Permite ao usuário adicionar uma nova tarefa.
- `void ExibirTarefas()`: Mostra todas as tarefas armazenadas.
- `void PesquisarTarefa()`: Busca uma tarefa pelo ID.
- `void DeletarTarefa()`: Remove uma tarefa com base no ID fornecido.
- `void AtualizarTarefa()`: Atualiza a descrição de uma tarefa com base no ID fornecido.

---

void Banner(): Exibe o título "Minhas Tarefas" no topo da tela.

void AdicionarTarefa(): Adiciona uma nova tarefa ao arquivo ListaTarefas.txt. O ID da tarefa é gerado automaticamente e o usuário é informado sobre o sucesso ou erro da operação.

void ExibirTarefas(): Exibe todas as tarefas armazenadas em ListaTarefas.txt. Se não houver tarefas, uma mensagem de aviso é exibida.

void PesquisarTarefa(): Permite ao usuário buscar uma tarefa pelo seu ID. Exibe os detalhes da tarefa encontrada ou uma mensagem caso não seja localizada.

void DeletarTarefa(): Deleta uma tarefa existente com base no ID fornecido. A tarefa é removida e o arquivo é atualizado, com uma mensagem informando o sucesso ou falha da operação.

void AtualizarTarefa(): Atualiza a descrição de uma tarefa com base no ID fornecido. A tarefa é atualizada e o arquivo é substituído com a versão modificada.

Arquivos Utilizados
ListaTarefas.txt: Armazena as tarefas no formato ID: Nomedaterefa.
Temp.txt: Arquivo temporário utilizado para operações de deleção e atualização.

## Fluxo Principal

1. O programa exibe o menu principal com as opções.
2. O usuário seleciona uma opção.
3. A função correspondente é executada.
4. O programa retorna ao menu até que o usuário escolha a opção de sair.

---

## Melhorias futuras

- Adicionar suporte para tarefas com datas e prioridades.
- Implementar uma interface gráfica para melhorar a experiência do usuário.
- Validar as entradas do usuário para evitar erros.
- Permitir a exclusão e atualização de múltiplas tarefas em uma única operação.


