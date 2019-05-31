function lerNomes(nomeArquivo)
    nomes = {}
    local numeroLinha = 0
    for linha in io.lines(nomeArquivo) do 
        numeroLinha =  numeroLinha + 1
        if (numeroLinha % 2 ~= 0) then
            nome = linha
        
        else
            nomes[nome] = linha
        end
    end
    return nomes
end

function geraTabelaAleatoria(tamanho)
    math.randomseed( os.time() )
    array = {}

    for i = 1, tamanho, 1 do
        array[i] = math.floor(math.random(1, 100))
    end

    return array
end

function quicksort(array, indice_inicio, indice_fim)
    local inicio = indice_inicio
    local fim = indice_fim
    local pivo = array[math.floor((indice_fim - indice_inicio)/2) + indice_inicio]
    while (inicio <= fim) do
        while (array[inicio] < pivo) do
            inicio = inicio + 1
        end
        while (array[fim] > pivo) do
            fim = fim - 1
        end
        if (inicio <= fim) then
            array[inicio], array[fim] = array[fim], array[inicio]
            inicio = inicio + 1
            fim = fim - 1
        end
    end
    if (indice_inicio < fim) then
        quicksort(array, indice_inicio, fim)
    end
    if inicio < indice_fim then
        quicksort(array, inicio, indice_fim)
    end
end

function quicksortCarrinho(carrinho, indice_inicio, indice_fim, indice_sort)
    local inicio = indice_inicio
    local fim = indice_fim
    local pivo = carrinho[math.floor((indice_fim - indice_inicio)/2) + indice_inicio][indice_sort]
    while (inicio <= fim) do
        while (carrinho[inicio][indice_sort] < pivo) do
            inicio = inicio + 1
        end
        while (carrinho[fim][indice_sort] > pivo) do
            fim = fim - 1
        end
        if (inicio <= fim) then
            carrinho[inicio][indice_sort], carrinho[fim][indice_sort] = carrinho[fim][indice_sort], carrinho[inicio][indice_sort]
            inicio = inicio + 1
            fim = fim - 1
        end
    end
    if (indice_inicio < fim) then
        quicksortCarrinho(carrinho, indice_inicio, fim, indice_sort)
    end
    if inicio < indice_fim then
        quicksortCarrinho(carrinho, inicio, indice_fim, indice_sort)
    end
end

function tabelaItens()
    local sair = false
    local itens = {}
    while sair == false do
        local item = {}
        io.write("Id: ")
        io.flush()
        id=io.read()
        item["id"] = id
        io.write("Preco: ")
        io.flush()
        preco=io.read()
        item[2] = preco
        io.write("Peso: ")
        io.flush()
        peso=io.read()
        item[3] = peso
        itens[table.getn(itens) + 1] = item
        io.write("Sair?")
        io.flush()
        continua=io.read()
        if continua == "s" then
            sair = true
        end
    end

    return itens
end

function tabelaItensAleatorios(tamanho)
    local itens = {}
    for i=1, tamanho, 1 do
        local item = {}
        item["id"] = math.random(1, 100)
        item[2] = math.random(1, 500)
        item[3] = math.random(1, 10)
        itens[#itens + 1] = item
    end

    return itens
end

function sum(a, b)
    return a + b
end
function sub(a, b)
    return a - b
end
function mul(a, b)
    return a * b
end
function div(a, b)
    return a / b
end

function teste1()
    local nomes = lerNomes("teste")
    for k, v in pairs (nomes) do
        print("Nome: ", k, "Sobrenome: ", v, "\n")
    end
end

function teste2()
    local array = geraTabelaAleatoria(5)
    for k, v in pairs (array) do
        print(v)
    end
    print("\n")
    quicksort(array, 1, table.getn(array))
    for k, v in pairs (array) do
        print(v)
    end
end

function teste3()
    local tabela = tabelaItensAleatorios(5)
    for k, v in pairs(tabela) do
        print("Preco: ", v[2])
    end
    print()
    quicksortCarrinho(tabela, 1, #tabela, 2)
    for k, v in pairs(tabela) do
        print("Preco: ", v[2])
    end
end

function teste4(tamanhoMochila)
    local itens = tabelaItensAleatorios(10)
    quicksortCarrinho(itens, 1, #itens, 2)
    local somaPesos = 0
    for k, v in pairs (itens) do
        print("| Id: ", v.id, "| Custo",v[2], "| Peso",v[3], "|")
        somaPesos = somaPesos + v[3]
    end
    print("\nSoma Pesos: ",somaPesos)

    local mochila = {}
    local peso = 0
    local custo = 0
    pesada = false
    while pesada == false do
        if peso + itens[#itens][3] > tamanhoMochila then
            pesada = true
        else
            mochila[#mochila + 1] = itens[#itens]
            peso = peso + itens[#itens][3]
            itens[#itens] = nil
            custo = custo + itens[#itens][2]
        end
    end
    print ("\nCarrinho")
    for k, v in pairs (itens) do
        print("| Id: ", v.id, "| Custo",v[2], "| Peso",v[3], "|")
        somaPesos = somaPesos + v[3]
    end
    print ("\nMochila")
    for k, v in pairs (mochila) do
        print("| Id: ", v.id, "| Custo",v[2], "| Peso",v[3], "|")
        somaPesos = somaPesos + v[3]
    end
    print("Peso mochila: ", peso)
    print("Custo mochila: ", custo)
end

function teste5(tamanhoMochila)
    local itens1 = tabelaItensAleatorios(10)

    quicksortCarrinho(itens1, 1, #itens1, 2)

    local mochila1 = {}
    local peso = 0
    local custo = 0
    local i = 0
    pesada = false
    while pesada == false do
        if peso + itens1[#itens1][3] > tamanhoMochila then
            pesada = true
        else
            mochila1[#mochila1 + 1] = itens1[#itens1 - i]
            peso = peso + itens1[#itens1][3]
            i = i + 1
        end
    end

    

    local somaPesos = 0
    local somaCusto = 0

    print ("\nCarrinho")
    for k, v in pairs (itens1) do
        print("| Id: ", v.id, "| Custo",v[2], "| Peso",v[3], "|")
        somaPesos = somaPesos + v[3]
        somaCusto = somaCusto + v[2]
    end
    print("Peso mochila: ", somaPesos)
    print("Custo mochila: ", somaCusto)

    somaPesos = 0
    somaCusto = 0
    print ("\nMochila Custo")
    for k, v in pairs (mochila1) do
        print("| Id: ", v.id, "| Custo",v[2], "| Peso",v[3], "|")
        somaPesos = somaPesos + v[3]
        somaCusto = somaCusto + v[2]
    end
    print("Peso mochila: ", somaPesos)
    print("Custo mochila: ", somaCusto)
    
    somaPesos = 0
    somaCusto = 0
    local itens2 = itens1
    for k, v in pairs (itens2) do
        v[4] = v[2]/v[3]
    end
    
    quicksortCarrinho(itens2, 1, #itens2, 4)

    local mochila2 = {}
    peso = 0
    custo = 0
    pesada = false
    while pesada == false do
        if peso + itens2[#itens2][3] > tamanhoMochila then
            pesada = true
        else
            mochila2[#mochila2 + 1] = itens2[#itens2]
            peso = peso + itens2[#itens2][3]
            itens2[#itens2] = nil
        end
    end
    print ("\nMochila Custo/Peso")
    for k, v in pairs (mochila2) do
        print("| Id: ", v.id, "| Custo",v[2], "| Peso",v[3], "|Custo/Peso",v[4], "|")
        somaPesos = somaPesos + v[3]
        somaCusto = somaCusto + v[2]
    end
    print("Peso mochila: ", somaPesos)
    print("Custo mochila: ", somaCusto)
end

function teste6()
    local continuar = true
    local listaFunc = {sum, sub, mul, div, math.pow}
    local a, b, c
    while continuar do
        os.execute("cls")
        io.write("Lista de Operacoes\n")
        io.write("1 | +\n")
        io.write("2 | -\n")
        io.write("3 | *\n")
        io.write("4 | /\n")
        io.write("5 | ^\n")
        io.write("\nEscolha uma operacao, ou 6 para sair:\n")
        io.flush()
        indice=io.read("*n")
        if indice > 5 then
            continuar = false
        else
            io.write("\nA:")
            io.flush()
            a=io.read("*n")
            io.write("\nB:")
            io.flush()
            b=io.read("*n")
            print("\nResultado: ", listaFunc[indice](a, b))
            io.flush()
            io.read()
            io.read()
        end
    end
end

math.randomseed(os.time())
-- teste1()
-- teste2()
-- teste3()
-- teste4(25)
-- teste5(25)
teste6()

