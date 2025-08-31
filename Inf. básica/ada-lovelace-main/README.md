# Trabalho sobre versionamento - GitHub

## Informações:
* Disciplina de Informática Básica - UFFS - Semestre 2024/2
* Discentes: 
    * Daniela do Nascimento Dalla Vecchia
    * Elen Leticia Pereira

### Pré-requisitos para rodar os comandos:
* Conta no github logada no navegador.
* git instalado.
* gh instalado (GitHub CLI) (Para criar um novo repositório a partir do diretório atual).

## Comandos realizados: 

#### Para iniciar o repositório: 
    git init
    // Iniciar o repositório

    gh auth login
    // Autenticar na conta onde será criado o repositório 
    // Com a conta logada no navegador, a autenticação é feita automaticamente (são dadas instruções via terminal para completar a autenticação)

    gh repo create ada-lovelace --public --source=. 
    // Criar um novo repositório a partir do diretório atual (com o projeto local criado)

#### Para fazer um commit: 
    git add .
    // Adicionar todas as alterações na staging area

    git commit -m "Mensagem do commit"
    // Fazer o commit junto de uma mensagem

    git push 
    // Subir as alterações para o repositório remoto 
    // Exemplo: git push --set-upstream origin main

#### Para criar uma branch: 
    git checkout -b branchEstudanteA
    // Criar e alternar para a branch

 
#### Para clonar um repositŕio:
    git clone https://github.com/daniela-ndv/ada-lovelace.git
    // Usado para clonar um repositório existente na máquina local

#### Para mergear as branches:
    git checkout main
    // Alterando para main 
    
    git merge EsudanteB
    // Fazer um merge da branch para a main

    git push
    // Envia as alterações