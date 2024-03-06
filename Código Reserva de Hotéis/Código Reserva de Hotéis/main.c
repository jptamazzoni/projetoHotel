#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int ncamas;
    int hotel;
    int quarto;
    int npessoas;
    int CheckinDia;
    int CheckinMes;
    int CheckinAno;
    int CheckoutDia;
    int CheckoutMes;
    int CheckoutAno;
    int fatura;
    int quantdia;
} Reserva;


typedef struct {
    char nome[50];
    long int cpf;
    long int telefone;
    Reserva reserva;
} Hospedes;


void main() {
    setlocale (LC_ALL, "Portuguese");
    int auxcafe, auxfatura, auxquantdia;
    int i=1;
    int analise;
    int contreserva=0;
    int codigo=0;
    Hospedes hospede[60];
    int pos=1;
    while(i<=60) {
        char menu;
        fflush(stdin);
        printf ("\n\n--=== Bem vindo a rede de hot�is GlamReserve!===---\n\n");
        printf ("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\n|Estamos felizes por voc� est� aqui e ansiosos para ajud�-lo\n|a encontrar a acomoda��o perfeita para a sua pr�xima viagem.\n");
        printf("|Explore nossas op��es de hot�is e comece a planejar sua estadia.\n");
        printf("|Obrigado por nos escolher para fazer parte da sua jornada!");
        printf("\n\n");
        do {
            printf("|O que voc� gostaria de fazer primeiro?|\n");
            printf("\n1. Fazer Nova Reserva");
            printf("\n2. Alterar Reserva");
            printf("\n3. Relat�rio do Hotel\n\n");
            printf("Digite o n�mero da sua escolha: ");
            scanf("%c", &menu);
            fflush(stdin);
            system("cls");
            printf("\n");
            if (menu!='1' && menu!='2' && menu!='3') {
                system("cls");
                printf ("\n\nEsta n�o � uma op��o v�lida! Tente novamente.\n\n");
            }
        } while(menu!='1' && menu!='2' && menu!='3');
        printf ("-------------------------------------------------------------------\n");
        switch(menu) {
        case '1':
            printf("|�timo, vamos l�!\n\n");
            printf("|Qual o seu nome completo?: ");
            scanf("%s", &hospede[i].nome);
            fflush(stdin);
            system("cls");
            printf ("-------------------------------------------------------------------\n");
            printf("\n|Qual o seu CPF?: ");
            scanf("%ld", &hospede[i].cpf);
            fflush(stdin);
            system("cls");
            printf ("-------------------------------------------------------------------\n");
            printf("\n|Certo! Agora me diga seu n�mero de telefone ou celular: ");
            scanf("%ld", &hospede[i].telefone);
            fflush(stdin);
            system("cls");

            printf ("\n-------------------------------------------------------------------\n");

//Reserva do Quarto
            printf("|Muito bem, agora vamos fazer a sua reserva!\n\n");
            do {
                printf("\n|Em qual de nossos hot�is voc� gostaria de se hospedar?\n");
                printf("\n1. Hotel GlamReserve [1]");
                printf("\n2. Hotel GlamReserve [2]");
                printf("\n3. Hotel GlamReserve [3]");
                printf("\n\n|Digite sua escolha: ");
                scanf("%d", &hospede[i].reserva.hotel);
                fflush(stdin);
                system("cls");
            } while(hospede[i].reserva.hotel!=1 && hospede[i].reserva.hotel!=2 && hospede[i].reserva.hotel!=3);

            printf ("\n-------------------------------------------------------------------\n");
            do {
                printf("|Temos um limite de 4 pessoas por reserva.");
                printf("\n|Caso deseje mais quartos para mais pessoas, ser� necess�rio realizar uma nova reserva no menu inicial.");
                printf ("\n\n|Para come�armos:");
                printf("\n");
                printf ("\n|Quantas pessoas fazem parte da reserva?: ");
                scanf("%d", &hospede[i].reserva.npessoas);
                auxcafe = hospede[i].reserva.npessoas;
                fflush(stdin);
                system("cls");
                if(hospede[i].reserva.npessoas > 4)
                    printf("\n\n|O n�mero de pessoas excede a quantidade m�xima!");
            } while(hospede[i].reserva.npessoas > 4);


            do {
                if(hospede[i].reserva.npessoas > 1) {
                    printf ("\n-------------------------------------------------------------------\n");
                    printf("\n|Temos os seguintes quartos disponiveis:\n");
                    printf("\n|Quarto com 1 cama  | Su�te Comum (R$500,00) e Su�te Presidencial(R$1000,00)|");
                    printf("\n|Quarto com 2 camas | Su�te Comum (R$550,00) e Su�te Presidencial(R$1100,00)|");

                    printf("\n\n|Quartos com 1 cama, possuem um banheiro.");
                    printf("\n|Quartos com 2 camas, possuem dois banheiro.");

                    printf("\n\n|Todas as camas s�o projetadas para acomodar at� 2 pessoas de forma espa�osa.");
                    printf("\n\n|Su�tes presidenciais possuem dimens�es maiores que as su�tes comuns.");
                    printf("\n|Su�tes presidenciais incluem al�m do quarto, uma sala de estar e varanda externa.");


                    printf ("\n-------------------------------------------------------------------\n");

                    do {
                        printf("\n|Quantas camas voc� gostaria para o quarto?: ");
                        scanf("%d", &hospede[i].reserva.ncamas);
                        fflush(stdin);
                        system("cls");
                        if(hospede[i].reserva.ncamas!=1 && hospede[i].reserva.ncamas!=2)
                            printf("\n\n<N�mero de camas indispon�vel!>\n\n");
                    } while(hospede[i].reserva.ncamas!=1 && hospede[i].reserva.ncamas!=2);

                    printf ("\n-------------------------------------------------------------------\n");

                    printf("\n\n|Para essa quantidade de camas temos os seguintes quartos: \n\n");
                    if(hospede[i].reserva.ncamas==1) {
                        printf("|Quartos do n�mero 100 ao 119.\n"); //20 quartos comuns
                        printf("|Sendo os respectivos quartos com su�tes comuns, localizados no 1� andar.\n\n");
                        printf("|Quartos do n�mero 200 ao 209.\n"); //10 quartos presidenciais
                        printf("|Sendo os respectivos quartos com su�tes presidencias, localizados no 2� andar.\n\n");
                        printf("|Qual o n�mero do quarto que voc� gostaria?: ");
                        scanf("%d", &hospede[i].reserva.quarto);
                        fflush(stdin);
                        if(hospede[i].reserva.quarto>=100 && hospede[i].reserva.quarto<=119) {
                            printf("\n\n|Voc� escolheu um quarto de su�te comum com uma cama.");
                            hospede[i].reserva.fatura = 500;
                            auxfatura = hospede[i].reserva.fatura;
                        }
                        if(hospede[i].reserva.quarto>=200 && hospede[i].reserva.quarto<=209) {
                            printf("\n\n|Voc� escolheu um quarto de su�te presidenciasl com uma cama.");
                            hospede[i].reserva.fatura = 1000;
                            auxfatura = hospede[i].reserva.fatura;
                        }

                    }

                    if(hospede[i].reserva.ncamas==2) {
                        printf("|Quartos do n�mero 300 ao 319.\n"); //20 quartos comuns
                        printf("|Sendo os respectivos quartos com su�tes comuns, localizados no 3� andar.\n\n");
                        printf("|Quartos do n�mero 400 ao 409.\n"); //10 quartos presidenciais
                        printf("|Sendo os respectivos quartos com su�tes presidenciais, localizados no 4� andar.\n\n");
                        printf("|Qual o n�mero do quarto que voc� gostaria?: ");
                        scanf("%d", &hospede[i].reserva.quarto);
                        fflush(stdin);
                        if(hospede[i].reserva.quarto>=300 && hospede[i].reserva.quarto<=319) {
                            printf("\n\n|Voc� escolheu um quarto de su�te comum com duas camas.");
                            hospede[i].reserva.fatura = 550;
                            auxfatura = hospede[i].reserva.fatura;
                        }
                        if(hospede[i].reserva.quarto>=400 && hospede[i].reserva.quarto<=409) {
                            printf("\n\n|Voc� escolheu um quarto de su�te presidencial com duas cama.");
                            hospede[i].reserva.fatura = 1100;
                            auxfatura = hospede[i].reserva.fatura;
                        }

                    }

                }

                if(hospede[i].reserva.npessoas == 1) {
                    hospede[i].reserva.ncamas=1;
                    printf("\n|Temos os seguintes quartos disponiveis para 1 pessoa:\n");
                    printf("\n|Quarto com 1 cama | Su�te Comum e Su�te Presidencial");
                    printf("\n\n|Quartos do n�mero 100 ao 119.\n");
                    printf("|Sendo os respectivos quartos com su�tes comuns, localizados no 1� andar.\n\n");
                    printf("|Quartos do n�mero 200 ao 209.\n");
                    printf("|Sendo os respectivos quartos com su�tes presidencias, localizados no 2� andar.\n\n");
                    printf("|Qual o n�mero do quarto que voc� gostaria?: ");
                    scanf("%d", &hospede[i].reserva.quarto);
                    fflush(stdin);
                    if(hospede[i].reserva.quarto>=100 && hospede[i].reserva.quarto<=119) {
                        printf("\n\n|Voc� escolheu um quarto de su�te comum com uma cama.");
                        hospede[i].reserva.fatura = 500;
                        auxfatura = hospede[i].reserva.fatura;
                    }
                    if(hospede[i].reserva.quarto>=200 && hospede[i].reserva.quarto<=209) {
                        printf("\n\n|Voc� escolheu um quarto de su�te presidenciasl com uma cama.");
                        hospede[i].reserva.fatura = 1000;
                        auxfatura = hospede[i].reserva.fatura;
                    }


                }
                system("cls");
                printf ("\n-------------------------------------------------------------------\n");
                printf("\n\n|Para quantos dias voc� pretende fazer sua reserva?: ");
                scanf("%d", &hospede[i].reserva.quantdia);
                auxquantdia = hospede[i].reserva.quantdia;
                fflush(stdin);
                system("cls");

//Check-In
                printf ("\n-------------------------------------------------------------------\n");
                printf("Qual a data do Check-In da reserva?\n\n");
                printf("<Insira apenas digitos num�ricos!>");
                printf("\n\nDia: ");
                scanf("%d", &hospede[i].reserva.CheckinDia);
                fflush(stdin);
                printf("\nM�s: ");
                scanf("%d", &hospede[i].reserva.CheckinMes);
                fflush(stdin);
                printf("\nAno: ");
                scanf("%d", &hospede[i].reserva.CheckinAno);
                fflush(stdin);

//Check-Out
                printf ("\n-------------------------------------------------------------------\n");
                printf("Qual a data do Check-Out da reserva?\n\n");
                printf("<Insira apenas digitos num�ricos!>");
                printf("\n\nDia: ");
                scanf("%d", &hospede[i].reserva.CheckoutDia);
                fflush(stdin);
                printf("\nM�s: ");
                scanf("%d", &hospede[i].reserva.CheckoutMes);
                fflush(stdin);
                printf("\nAno: ");
                scanf("%d", &hospede[i].reserva.CheckoutAno);
                fflush(stdin);
                system("cls");


//Analise de Disponibilidade
                analise = 0;

                for(i=1; i < pos ; i++) {

                    if((hospede[pos].reserva.hotel == hospede[i].reserva.hotel) && (hospede[pos].reserva.quarto == hospede[i].reserva.quarto) && ((
                                ((hospede[pos].reserva.CheckinDia >= hospede[i].reserva.CheckinDia) && (hospede[pos].reserva.CheckinDia <= hospede[i].reserva.CheckoutDia)) &&
                                ((hospede[pos].reserva.CheckinMes >= hospede[i].reserva.CheckinMes) && (hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckoutMes)) &&
                                ((hospede[pos].reserva.CheckinAno >= hospede[i].reserva.CheckinAno) && (hospede[pos].reserva.CheckinAno <= hospede[i].reserva.CheckoutAno))
                            )
                            ||
                            (
                                ((hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia) && (hospede[pos].reserva.CheckoutDia <= hospede[i].reserva.CheckoutDia)) &&
                                ((hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes) && (hospede[pos].reserva.CheckoutMes <= hospede[i].reserva.CheckoutMes)) &&
                                ((hospede[pos].reserva.CheckoutAno >= hospede[i].reserva.CheckinAno) && (hospede[pos].reserva.CheckoutAno <= hospede[i].reserva.CheckoutAno))
                            ))
                        )
                        {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

                }


            } while(analise>0);
            pos++;

//Fatura da Reserva

            int valorQuarto = auxfatura;
            int servicoQuarto = 100;
            int cafeManha = 40 * auxcafe; //aux1 recebe o n�mero de pessoas
            int valorDiaria = (valorQuarto + cafeManha + servicoQuarto);
            int valorTotal = (valorQuarto + cafeManha + servicoQuarto) * auxquantdia;
            system("cls");

            printf ("\n-------------------------------------------------------------------\n");

            printf("|Muito bem!\n");
            printf("|Aqui est� sua fatura com todos os respectivos servi�os e valores de sua estadia: \n\n");
            printf("|Di�ria do Quarto: R$%d,00", valorQuarto);
            printf("\n|Servi�o de Quarto: R$%d,00 (R$100,00 por dia)", servicoQuarto*auxquantdia);
            printf("\n|Caf� da Manh�: R$%d,00 (R$40,00 por pessoa diariamente)", cafeManha*auxquantdia);
            printf("\n\n|Valor total da di�ria: R$%d,00", valorDiaria);
            printf("\n|Valor total da reserva: R$%d,00", valorTotal);

            printf("\n\n|O valor de sua fatura � de R$%d,00 por dia ou R$%d,00 no total.", valorDiaria, valorTotal);

            printf("\n\n< Valores como |Caf� da Manh�| e |Servi�o de Quarto| s�o fixos, portanto n�o � poss�vel retir�-los de sua reserva >.\n");


            printf ("\n-------------------------------------------------------------------\n");
            codigo++;
            contreserva++;
            i++;
            printf("|Aqui est� seu c�digo de seguran�a: [%d].", codigo); //Exemplo simples de c�digo de acesso
            printf("\n|Este c�digo � utilizado como chave de acesso para alterar dados de sua reserva.");

            printf ("\n-------------------------------------------------------------------\n");


//Agradecimentos
            printf("\n|Obrigado por escolher a rede de Hot�is GlamReserve!\n");
            printf("|Sua reserva foi confirmada com sucesso e estamos ansiosos para receb�-lo em breve.\n");
            printf("|Esperamos que tenha uma boa viagem e uma �tima estadia!\n\n");

            printf("Ficamos � disposi��o para ajudar com qualquer d�vida ou solicita��o adicional que possa ter antes da sua chegada.");

            printf ("\n\n-------------------------------------------------------------------\n\n");
            printf("|Pressicone [ENTER] para retornar ao �nico.");
            getchar();
            system("cls");
            break;

//===============================================================================================================================================================



//Alterar Reserva

            char menu2;
        case '2':
            if(codigo < 1) {
                printf("N�o h� nenhuma reserva cadastrada!");
                printf ("\n-------------------------------------------------------------------\n\n");
                printf("|Pressicone [ENTER] para retornar ao �nico.");
                getchar();
                system("cls");
            default:
                break;
            }


            do {
                printf("\n\n|O que voc� deseja fazer?");
                printf("\n\n1. Alterar Quarto e Datas");
                printf("\n2. Cancelar Reserva");
                printf("\n\nDigite o n�mero da sua escolha: ");
                scanf("%c", &menu2);
                fflush(stdin);
                if (menu!='1' && menu!='2' && menu!='3')
                    printf ("\n\nEsta n�o � uma op��o v�lida! Tente novamente.\n\n");

            } while(menu2!='1' && menu2!='2');

            switch(menu2) {
                int alterar;
                int cancelar;
            case '1':

                printf ("\n\n-------------------------------------------------------------------\n\n");
                printf("\n\n|Digite a chave de acesso da reserva: ");
                scanf("%d", &alterar);
                fflush(stdin);
                i=alterar;
                if(hospede[i].reserva.quarto==0) {
                    system("cls");
                    printf ("\n\n-------------------------------------------------------------------\n\n");
                    printf("\n|Esta reserva est� cadastrada!\n\n");
                    printf("|Pressicone [ENTER] para retornar ao �nico.");
                    getchar();
                    system("cls");
                    break;
                }

                hospede[i].reserva.CheckinDia=0;
                hospede[i].reserva.CheckinMes=0;
                hospede[i].reserva.CheckinAno=0;
                hospede[i].reserva.CheckoutDia=0;
                hospede[i].reserva.CheckoutMes=0;
                hospede[i].reserva.CheckoutAno=0;
                hospede[i].reserva.quarto=0;
                hospede[i].reserva.quantdia=0;
                hospede[i].reserva.ncamas=0;
                hospede[i].reserva.npessoas=0;
                hospede[i].reserva.fatura=0;

                printf ("\n\n-------------------------------------------------------------------\n\n");

                printf("\n\n|Certo, vamos alterar sua reserva!");
                printf("\n|Para isso, vamos pedir que insira novamente as novas informa��es de sua reserva.");
                printf("\n\n|Vamos l�!");

                do {
                    printf("\n|Em qual de nossos hot�is voc� gostaria de se hospedar?\n");
                    printf("\n1. Hotel [1]");
                    printf("\n2. Hotel [2]");
                    printf("\n3. Hotel [3]");
                    printf("\n\n|Digite sua escolha: ");
                    scanf("%d", &hospede[i].reserva.hotel);
                    fflush(stdin);
                    system("cls");
                } while(hospede[i].reserva.hotel!=1 && hospede[i].reserva.hotel!=2 && hospede[i].reserva.hotel!=3);

                do {
                    printf ("\n|Quantas pessoas fazem parte da reserva?: ");
                    scanf("%d", &hospede[i].reserva.npessoas);
                    fflush(stdin);
                    auxcafe=hospede[i].reserva.npessoas;
                    system("cls");

                    if(hospede[i].reserva.npessoas > 4) {
                        printf ("\n-------------------------------------------------------------------\n");
                        printf("\n\n<O n�mero de pessoas excede a quantidade m�xima!>");
                        printf ("\n-------------------------------------------------------------------\n");
                    }
                } while(hospede[i].reserva.npessoas > 4);


                do {
                    if(hospede[i].reserva.npessoas > 1) {
                        printf ("\n\n-------------------------------------------------------------------\n\n");

                        printf("\n|Temos os seguintes quartos disponiveis:\n");
                        printf("\n|Quarto com 1 cama  | Su�te Comum (R$500,00) e Su�te Presidencial(R$1000,00)|");
                        printf("\n|Quarto com 2 camas | Su�te Comum (R$550,00) e Su�te Presidencial(R$1100,00)|");

                        printf("\n\n|Quartos com 1 cama, possuem um banheiro.");
                        printf("\n|Quartos com 2 camas, possuem dois banheiro.");

                        printf("\n\n|Todas as camas s�o projetadas para acomodar at� 2 pessoas de forma espa�osa.");
                        printf("\n\n|Su�tes presidenciais possuem dimens�es maiores que as su�tes comuns.");
                        printf("\n)|Su�tes presidenciais incluem al�m do quarto, uma sala de estar e varanda externa.");



                        do {
                            printf ("\n\n-------------------------------------------------------------------\n\n");
                            printf("\n|Quantas camas voc� gostaria para o quarto?: ");
                            scanf("%d", &hospede[i].reserva.ncamas);
                            fflush(stdin);
                            system("cls");
                        } while(hospede[i].reserva.ncamas!=1 && hospede[i].reserva.ncamas!=2);

                        printf ("\n-------------------------------------------------------------------\n");

                        printf("\n\n|Para essa quantidade de camas temos os seguintes quartos: \n");
                        if(hospede[i].reserva.ncamas==1) {
                            printf("|Quartos do n�mero 100 ao 119.\n");
                            printf("|Sendo os respectivos quartos com su�tes comuns, localizados no 1� andar.\n\n");
                            printf("|Quartos do n�mero 200 ao 209.\n");
                            printf("|Sendo os respectivos quartos com su�tes presidencias, localizados no 2� andar.\n\n");
                            printf("|Qual o n�mero do quarto que voc� gostaria?: ");
                            scanf("%d", &hospede[i].reserva.quarto);
                            fflush(stdin);
                            if(hospede[i].reserva.quarto>=100 && hospede[i].reserva.quarto<=119) {
                                printf("\n\n|Voc� escolheu um quarto de su�te comum com uma cama.");
                                hospede[i].reserva.fatura = 500;
                                auxfatura = hospede[i].reserva.fatura;
                            }
                            if(hospede[i].reserva.quarto>=200 && hospede[i].reserva.quarto<=209) {
                                printf("\n\n|Voc� escolheu um quarto de su�te presidenciasl com uma cama.");
                                hospede[i].reserva.fatura = 1000;
                                auxfatura = hospede[i].reserva.fatura;
                            }
                        }

                        if(hospede[i].reserva.ncamas==2) {
                            printf("|Quartos do n�mero 300 ao 319.\n");
                            printf("|Sendo os respectivos quartos com su�tes comuns, localizados no 3� andar.\n\n");
                            printf("|Quartos do n�mero 400 ao 409.\n");
                            \
                            printf("|Sendo os respectivos quartos com su�tes presidenciais, localizados no 4� andar.\n\n");
                            printf("|Qual o n�mero do quarto que voc� gostaria?: ");
                            scanf("%d", &hospede[i].reserva.quarto);
                            fflush(stdin);
                            if(hospede[i].reserva.quarto>=300 && hospede[i].reserva.quarto<=319) {
                                printf("\n\n|Voc� escolheu um quarto de su�te comum com duas camas.");
                                hospede[i].reserva.fatura = 550;
                                auxfatura = hospede[i].reserva.fatura;
                            }
                            if(hospede[i].reserva.quarto>=400 && hospede[i].reserva.quarto<=409) {
                                printf("\n\n|Voc� escolheu um quarto de su�te presidencial com duas cama.");
                                hospede[i].reserva.fatura = 1100;
                                auxfatura = hospede[i].reserva.fatura;
                            }

                        }


                    }

                    if(hospede[i].reserva.npessoas == 1) {
                        hospede[i].reserva.ncamas=1;
                        printf("\n|Temos os seguintes quartos disponiveis para 1 pessoa:\n");
                        printf("\n|Quarto com 1 cama | Su�te Comum e Su�te Presidencial");
                        printf("\n\n|Quartos do n�mero 100 ao 119.\n");
                        printf("|Sendo os respectivos quartos com su�tes comuns, localizados no 1� andar.\n\n");
                        printf("|Quartos do n�mero 200 ao 209.\n");
                        printf("|Sendo os respectivos quartos com su�tes presidencias, localizados no 2� andar.\n\n");
                        printf("|Qual o n�mero do quarto que voc� gostaria?: ");
                        scanf("%d", &hospede[i].reserva.quarto);
                        fflush(stdin);
                        if(hospede[i].reserva.quarto>=100 && hospede[i].reserva.quarto<=119) {
                            printf("\n\n|Voc� escolheu um quarto de su�te comum com uma cama.");
                            hospede[i].reserva.fatura = 500;
                            auxfatura = hospede[i].reserva.fatura;
                        }
                        if(hospede[i].reserva.quarto>=200 && hospede[i].reserva.quarto<=209) {
                            printf("\n\n|Voc� escolheu um quarto de su�te presidenciasl com uma cama.");
                            hospede[i].reserva.fatura = 1000;
                            auxfatura = hospede[i].reserva.fatura;
                        }
                    }
                    system("cls");
                    printf ("\n-------------------------------------------------------------------\n");

                    printf("\n\n|Para quantos dias voc� pretende fazer sua reserva?: ");
                    scanf("%d", &hospede[i].reserva.quantdia);
                    fflush(stdin);
                    auxquantdia = hospede[i].reserva.quantdia;
                    fflush(stdin);
                    system("cls");

//Check-In
                    printf ("\n-------------------------------------------------------------------\n");
                    printf("Qual a data do Check-In da reserva?\n");
                    printf("<Insira apenas digitos num�ricos!>");
                    printf("\n\nDia: ");
                    scanf("%d", &hospede[i].reserva.CheckinDia);
                    printf("%d", hospede[i].reserva.CheckinDia);
                    fflush(stdin);
                    printf("\nM�s: ");
                    scanf("%d", &hospede[i].reserva.CheckinMes);
                    fflush(stdin);
                    printf("\nAno: ");
                    scanf("%d", &hospede[i].reserva.CheckinAno);

                    fflush(stdin);

//Check-Out
                    printf ("\n-------------------------------------------------------------------\n");

                    printf("Qual a data do Check-Out da reserva?\n");
                    printf("<Insira apenas digitos num�ricos!>");
                    printf("\n\nDia: ");
                    scanf("%d", &hospede[i].reserva.CheckoutDia);
                    fflush(stdin);
                    printf("\nM�s: ");
                    scanf("%d", &hospede[i].reserva.CheckoutMes);
                    fflush(stdin);
                    printf("\nAno: ");
                    scanf("%d", &hospede[i].reserva.CheckoutAno);
                    fflush(stdin);


//Analise de Disponibilidade
                    analise = 0;

                    for(i=1; i < pos ; i++) {

                        if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia == hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes == hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, mesmo dia, mesmo m�s, mesmo ano



                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes == hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia <= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes == hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia diferente, mesmo m�s e mesmo ano, checkout mesmo m�s ou maior, mesmo ano, dia maior ou igual)

                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia <= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes == hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia <= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes == hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }



                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutAno >= hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia menor de checkin, mes menor de checkin, mesmo ano, checkout no pr�ximo m�s, dia maior que checkin e menor que checkout



                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia <= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia <= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckoutMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia menor de checkin, mes menor de checkin, mesmo ano, checkout no pr�ximo m�s, dia maior que checkin e menor que checkout

                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia <= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckoutMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }
//Mesmo quarto, dia menor de checkin, mes menor de checkin, mesmo ano, checkout no pr�ximo m�s, dia maior que checkin e maior que checkout


                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia <= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckoutMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia maior de checkin, mes menor de checkin, mesmo ano, checkout no pr�ximo m�s, dia maior que checkin e menor que checkout


                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckoutMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia maior de checkin, mes menor de checkin, mesmo ano, checkout no pr�ximo m�s, dia maior que checkin e maior que checkout

                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia == hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckoutMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia maior de checkin, mes menor de checkin, mesmo ano, checkout no pr�ximo m�s, dia igual o checkin

                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia <= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia == hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckoutMes && hospede[pos].reserva.CheckoutAno == hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia menor de checkin, mes menor de checkin, mesmo ano, checkout no pr�ximo m�s, dia igual o checkin


                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes <= hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno == hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia <= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia <= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes > hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutMes >= hospede[i].reserva.CheckoutMes && hospede[pos].reserva.CheckoutAno > hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia diferente, m�s difente, mesmo ano, checkout pr�ximo m�s, pr�ximo ano, dia menor ou igual)




                        else if (hospede[pos].reserva.hotel == hospede[i].reserva.hotel && hospede[pos].reserva.quarto == hospede[i].reserva.quarto && hospede[pos].reserva.CheckinDia <= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckinMes != hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckinAno != hospede[i].reserva.CheckinAno && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckinDia && hospede[pos].reserva.CheckoutDia >= hospede[i].reserva.CheckoutDia && hospede[pos].reserva.CheckoutMes < hospede[i].reserva.CheckinMes && hospede[pos].reserva.CheckoutAno > hospede[i].reserva.CheckinAno) {
                            printf ("\n\n|Reserva Indipon�vel!\n|Tente novamente com quartos ou datas diferentes.");
                            analise++;
                        }

//Mesmo quarto, dia diferente, m�s diferente, ano diferente, checkout pr�ximo m�s , pr�ximo ano, dia igual ou maior)

                    }


                } while(analise>0);
                pos++;

//Fatura da Reserva
                int valorQuarto = auxfatura;
                int servicoQuarto = 100;
                int cafeManha = 40 * auxcafe;
                int valorDiaria = (valorQuarto + cafeManha + servicoQuarto);
                int valorTotal = (valorQuarto + cafeManha + servicoQuarto) * auxquantdia;

                system("cls");
                printf("|Muito bem!\n");
                printf("|Aqui est� sua nova fatura com todos os respectivos servi�os e valores de sua estadia ap�s a altera��o: \n\n");

                printf("|Di�ria do Quarto: R$%d,00", valorQuarto);
                printf("\n|Servi�o de Quarto: R$%d,00 (R$100,00 por dia)", servicoQuarto*auxquantdia);
                printf("\n|Caf� da Manh�: R$%d,00 (R$40,00 por pessoa diariamente)", cafeManha*auxquantdia);
                printf("\n\n|Valor total da di�ria: R$%d,00", valorDiaria);
                printf("\n|Valor total da reserva: R$%d,00", valorTotal);

                printf("\n\n|O valor de sua fatura � de R$%d,00 por dia ou R$%d,00 no total.", valorDiaria, valorTotal);

                printf("\n\n< Valores como |Caf� da Manh�| e |Servi�o de Quarto| s�o fixos, portanto n�o � poss�vel retir�-los de sua reserva >.");

                printf ("\n\n-------------------------------------------------------------------\n\n");

                printf("\n\n|Sua reserva foi alterada com sucesso!");
                printf("\n\n|O seu c�digo de seguran�a permanece o mesmo: [%d].", codigo);

                printf ("\n\n-------------------------------------------------------------------\n\n");


//Agradecimentos
                printf("\n\n\n|Obrigado por escolher a rede de Hot�is GlamReserve!\n");
                printf("|Sua reserva foi confirmada com sucesso e estamos ansiosos para receb�-lo em breve.\n");
                printf("|Esperamos que tenha uma boa viagem e uma �tima estadia!\n\n");

                printf("Ficamos � disposi��o para ajudar com qualquer d�vida ou solicita��o adicional que possa ter antes da sua chegada.");

                printf ("\n\n-------------------------------------------------------------------\n\n");
                printf("\n\n|Pressicone [ENTER] para retornar ao �nico.");
                getchar();
                system("cls");
                break;


//Case 2 - Cancelar Reserva
            case '2':

                printf ("\n\n-------------------------------------------------------------------\n");
                int rcancelar=0;
                printf("\n|Digite a chave de acesso da reserva: ");
                scanf("%d", &cancelar);
                fflush(stdin);
                i=cancelar;
                if(hospede[i].reserva.quarto==0) {
                    system("cls");
                    printf ("\n\n-------------------------------------------------------------------\n\n");
                    printf("\n|Esta reserva n�o est� cadastrada!\n\n");
                    printf("|Pressicone [ENTER] para retornar ao �nico.");
                    getchar();
                    system("cls");
                    break;
                }

                system("cls");
                i=cancelar;
                printf("|Caso cancele sua reserva, ser� necess�rio se cadastrar novamente\n para realizar uma nova reserva.\n\n");
                printf("|Deseja mesmo cancelar sua reserva?");
                printf("\n\n1. Sim");
                printf("\n\n2. N�o");
                printf("\n\n|Digite sua escolha: ");
                scanf("%d", &rcancelar);
                fflush(stdin);

                if(rcancelar==1) {
                    printf ("\n\n-------------------------------------------------------------------\n\n");
                    system("cls");
                    printf("|Reserva cancelada com sucesso!");
                    hospede[i].reserva.CheckinDia=0;
                    hospede[i].reserva.CheckinMes=0;
                    hospede[i].reserva.CheckinAno=0;
                    hospede[i].reserva.CheckoutDia=0;
                    hospede[i].reserva.CheckoutMes=0;
                    hospede[i].reserva.CheckoutAno=0;
                    hospede[i].reserva.quarto=0;
                    hospede[i].reserva.quantdia=0;
                    hospede[i].reserva.ncamas=0;
                    hospede[i].reserva.npessoas=0;
                    hospede[i].reserva.fatura=0;
                    contreserva--;
                }

                if(rcancelar==2) {
                    system("cls");
                    printf ("\n\n-------------------------------------------------------------------\n\n");
                    printf("|Voc� escolheu n�o cancelar sua reserva. Nenhuma altera��o foi realizada.");
                }

                printf("\n\n|Pressicone [ENTER] para retornar ao �nico.");
                getchar();
                system("cls");
                break;

            }//Switch 2
            break;


//Relat�rio de Reservas
            long int senha;
        case'3':
                system("cls");
            printf ("\n-------------------------------------------------------------------\n\n");
            printf("|Este recurso est� dispon�vel somente para membros da equipe do hotel.\n");
            printf("|Para obter acesso a esta op��o, digite a senha de gerenciamento.");
            do {
                senha=0;
                printf("\n\n|Digite a senha: ");
                scanf("%ld", &senha);
                fflush(stdin);
                if (senha!=12345) {
                    printf("\n\n|Senha incorreta!");
                    printf("\n|Por favor, tente novamente.\n");
                }
            } while(senha!=12345);


            if (senha==12345) {
                system("cls");
                printf("\n\n|Senha correta!\n");
                printf("|Exibindo relat�rio de informa��es: \n");
                if(hospede[i].reserva.quarto!='0') {
                    for(i=1; i<=contreserva; i++) {
                        printf("\n|Nome: %s", hospede[i].nome);
                        printf("\n|Hotel: Hotel [%d]", hospede[i].reserva.hotel);
                        printf("\n|Quarto: %d", hospede[i].reserva.quarto);
                        printf("\n|N� de pessoas: %d", hospede[i].reserva.npessoas);
                        printf("\n|N� de camas: %d", hospede[i].reserva.ncamas);
                        printf("\n|Checkin: %d/%d/%d", hospede[i].reserva.CheckinDia, hospede[i].reserva.CheckinMes, hospede[i].reserva.CheckinAno);
                        printf("\n|Checkout: %d/%d/%d", hospede[i].reserva.CheckoutDia, hospede[i].reserva.CheckoutMes, hospede[i].reserva.CheckoutAno);
                        printf("\n|Quantidade de Dias: %d", hospede[i].reserva.quantdia);
                        printf("\n|Fatura: R$%d,00", (hospede[i].reserva.fatura*hospede[i].reserva.quantdia)+(servicoQuarto*hospede[i].reserva.quantdia)+(cafeManha*hospede[i].reserva.quantdia));
                        printf("\n\n");


                    }//For das Impress�es do Relat�rio

                }//Segundo IF
            }//Primeiro IF

            printf ("\n-------------------------------------------------------------------\\n");
            printf("\n\n|Pressicone [ENTER] para retornar ao �nico.");
            getchar();
            system("cls");
            break;



        } //Switch Principal

    } //For geral

} // Main
