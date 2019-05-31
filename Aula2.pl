use strict;
use warnings;

sub exercicio0{
    my $n = shift;
    if ($n < 2){
        return $n;
    }
    else {
        return exercicio0($n - 1) + exercicio0($n -2);
    }   
}

sub fib_bom{
    my $n = shift;
    my $fib1 = 1;
    my $fib2 = 1;
    my $tfib = 1;

    for my $i (1 .. $n){
        if ($i > 2){
            $tfib = $fib2;
            $fib2 = $fib1 + $fib2;
            $fib1 = $tfib;
        }
    }

    return $tfib;
}


sub getNomes{
    open(my $arquivo,  "<",  "teste")  or die "Nao deu pra abrir o  arquivo: $!";

    my $i = 0;
    my $nome;
    my %nomes;
    while (my $linha = <$arquivo>) {
        $i++;
        chomp $linha;
        if ($i % 2 == 0){
            $nomes{$nome} = $linha;
        }
        else{
            $nome = $linha;
        }
    }
    close($arquivo);
    return %nomes;
}

sub nomeRepetido(){
    open(my $arquivo,  "<",  "teste")  or die "Nao deu pra abrir o  arquivo: $!";
    my @linhas = <$arquivo>;
    while (my ($k, $linha)=each @linhas) {
        my @repeticoes = grep { /$linha/g } @linhas;
        if (scalar @repeticoes > 1){
            $linha =~ s/\n//;
            print( "Repeticao encontrada: ", $linha, "\n");
        }
    }
    close($arquivo);
}

sub numeroLinhas{
    open(my $arquivo,  "<", shift)  or die "Nao deu pra abrir o  arquivo: $!";
    my @linhas = <$arquivo>;
    close($arquivo);
    return scalar @linhas;
}

sub numeroPalavras{
    open(my $arquivo,  "<", shift)  or die "Nao deu pra abrir o  arquivo: $!";
    my $numero = 0;
    while (my $linha = <$arquivo>) {
        chomp $linha;
        my @palavras = split(/ /,$linha);
        $numero += scalar @palavras;
    }
    close($arquivo);
    return $numero;
}

sub numeroChars{
    open(my $arquivo,  "<", shift)  or die "Nao deu pra abrir o  arquivo: $!";
    my $numero = 0;
    while (my $linha = <$arquivo>) {
        chomp $linha;
        $numero += length($linha);
    }
    close($arquivo);
    return $numero;
}

sub numeroCharsS{
    open(my $arquivo,  "<", shift)  or die "Nao deu pra abrir o  arquivo: $!";
    my $numero = 0;
    while (my $linha = <$arquivo>) {
        chomp $linha;
        $linha =~ s/ //g;
        $numero += length($linha);
    }
    close($arquivo);
    return $numero;
}


sub cacaPalavras{
    open(my $arquivo,  "<", shift)  or die "Nao deu pra abrir o  arquivo: $!";
    my $encontradas = 0;
    my @regexPalavras = (@_);
    my $conteudoArquivo = join "", <$arquivo>;
    while (my ($k,$regexPalavra)=each @regexPalavras){
        if(my @count = $conteudoArquivo =~ /$regexPalavra/gi){
            $encontradas += scalar @count;
        }   
    }
    close($arquivo);
    return $encontradas;
}

sub geraPalavras{
    my @regex = (
        "c[o|0]mpr[a|@]",
        "v[e|&]nd[a|@]",
        "gr[a|@|á]t[i|1]",
        "c[@|a]rt[a|ã|@][o|0]"
    );
    return @regex;
}

sub teste1{
    my %listaNomes = getNomes();
    while (my ($k,$v)=each %listaNomes){
        print "$k $v\n";
    }
}

sub teste2{
    nomeRepetido();
}

sub teste3{
    
    print ("Numero de linhas: ", numeroLinhas("arquivo_teste.txt"), "\n");
    print ("Numero de palavras: ", numeroPalavras("arquivo_teste.txt"), "\n");
    print ("Numero de caracteres: ", numeroChars("arquivo_teste.txt"), "\n");
    print ("Numero de caracteres não espaço: ", numeroCharsS("arquivo_teste.txt"), "\n");
}

sub teste4{
    my @regexPalavras = geraPalavras("regex.txt");
    my $encontradas = cacaPalavras("spam.txt", @regexPalavras);
    print($encontradas);
}

# teste2();
# teste3();
teste4();

