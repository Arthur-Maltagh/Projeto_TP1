# Contribuições da equipe

## Arthur
- Classe domínio Nome
- Classe domínio Limite
- Classe domínio Identificador
- Classe domínio Senha
- Classe domínio EMAIL
- Classe domínio Timestamp
- Testes unitários dos domínios acima
- Documentação das classes acima
- Interfaces
- Documentação das interfaces
- Diagrama UML da arquitetura de software
- Módulo de apresentação da entidade Pessoa (MAPE)
- Módulo de serviço da entidade Pessoa (MSPE)
- Stub e Driver da entidade Pessoa
- container da entidade pessoa
- Módulo de Apresentação da Interface de Controle (MAIC)
- Módulo de Apresentação da Autenticação (MAAU)
- Módulo de serviço da Autenticação (MSAU)
- stub e driver do módulo de autenticação
- driver do módulo MAIC

## João Victor
- Módulo de apresentação de Projetos (MAPR)
- Módulo de serviço de Projetos (MSPR)
- Contêiner de projetos e testes do serviço de projetos

## Responsabilidades do módulo de Projetos

- `CntrIAprProjeto` (MAPR): identifica o papel do usuário autenticado, apresenta as opções permitidas, valida os dados de entrada com as classes de domínio e encaminha as solicitações para `ISerProjeto`.
- `CntrISerProjeto` (MSPR): implementa `ISerProjeto`, coordena as operações sobre projetos e consulta o serviço de quadros para verificar dependências antes da exclusão.
- `ContainerProjeto`: armazena os dados dos projetos e o email do gestor que criou cada projeto.
- A exclusão de um projeto é recusada quando ele possui quadros associados. A apresentação informa quantos quadros existem e orienta o usuário a excluí-los primeiro. O projeto também é preservado quando não é possível consultar o serviço de quadros. A exclusão de um quadro, por sua vez, deve ser recusada enquanto houver cartões associados.
- `TesteISerProjeto`: verifica criação, duplicidade, leitura, atualização, listagem, associação do gestor, contagem de quadros e recusa de exclusão quando há dependências ou quando a consulta não está disponível.

O módulo de apresentação acessa a navegação para quadros por meio de `IAprQuadro`. O módulo de serviço depende de `ISerQuadro` para listar os quadros associados a um projeto e impedir a exclusão enquanto houver dependências.

## Maria Eduarda
- Classe domínio Papel
- Classe domínio Estado
- Classe domínio Prioridade
- Classe domínio Tamanho
- Testes unitários dos domínios acima
- Documentação das classes acima

## Murilo
- Classe entidade Pessoa
- Classe entidade CartaoAtividade
- Classe entidade Projeto
- Classe entidade Quadro
- Documentação das classes acima
- Testes unitários das classes acima

## Como executar os testes

1. Abra `Projeto_TP1.cbp` no Code::Blocks.
2. Selecione o alvo de compilação `Tests`.
3. Compile e execute o projeto.
4. No menu de testes, a opção `1` executa os testes de domínios e entidades; a opção `6` executa os testes do serviço de projetos.

O arquivo `Doxyfile` usa caminhos relativos ao diretório do projeto. Com o Doxygen instalado, execute `doxygen Doxyfile` na raiz para gerar a documentação HTML atualizada.
