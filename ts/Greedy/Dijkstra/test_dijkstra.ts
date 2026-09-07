import { strict as assert } from "node:assert";
import { Dijkstra } from "./Dijkstra";
import { MinPriorityQueue } from "./minPriorityQueue";
import { MyGraph } from "./MyGraph";

function testMinPriorityQueue(): void {
    const cola = new MinPriorityQueue<string>();

    assert.equal(cola.isEmpty, true);
    assert.equal(cola.length, 0);
    assert.equal(cola.pop(), undefined);

    cola.push(5, "cinco");
    cola.push(1, "uno");
    cola.push(3, "tres");

    assert.equal(cola.length, 3);
    assert.deepEqual(cola.pop(), [1, "uno"]);
    assert.deepEqual(cola.pop(), [3, "tres"]);
    assert.deepEqual(cola.pop(), [5, "cinco"]);
    assert.equal(cola.isEmpty, true);
}

function testGraph(): void {
    const grafo = new MyGraph();
    grafo.agregarArista("A", "B", 4);

    assert.equal(grafo.tieneVertice("A"), true);
    assert.equal(grafo.tieneVertice("B"), true);
    assert.deepEqual(grafo.getVecinos("A"), [{ destino: "B", peso: 4 }]);
    assert.deepEqual(grafo.getVecinos("B"), [{ destino: "A", peso: 4 }]);

    assert.throws(
        () => grafo.agregarArista("A", "C", -1),
        /pesos negativos: -1/
    );
    assert.throws(
        () => grafo.getVecinos("NoExiste"),
        /No existe el nodo: NoExiste/
    );

    const grafoDirigido = new MyGraph(true);
    grafoDirigido.agregarArista("A", "B", 4);
    assert.deepEqual(grafoDirigido.getVecinos("B"), []);
}

function testDijkstra(): void {
    const grafo = new MyGraph();
    grafo.agregarArista("A", "B", 10);
    grafo.agregarArista("A", "C", 2);
    grafo.agregarArista("C", "D", 3);
    grafo.agregarArista("D", "B", 1);
    grafo.agregarVertice("Isla");

    const resultado = Dijkstra.resolver(grafo, "A");

    assert.equal(resultado.distancias.get("A"), 0);
    assert.equal(resultado.distancias.get("B"), 6);
    assert.equal(resultado.distancias.get("Isla"), Infinity);
    assert.deepEqual(resultado.trayecto("B"), ["A", "C", "D", "B"]);
    assert.deepEqual(resultado.trayecto("A"), ["A"]);
    assert.deepEqual(resultado.trayecto("Isla"), []);
    assert.deepEqual(resultado.trayecto("NoExiste"), []);

    const dirigido = new MyGraph(true);
    dirigido.agregarArista("Inicio", "Medio", 5);
    dirigido.agregarArista("Medio", "Fin", 4);

    const resultadoDirigido = Dijkstra.resolver(dirigido, "Fin");
    assert.equal(resultadoDirigido.distancias.get("Inicio"), Infinity);
    assert.deepEqual(resultadoDirigido.trayecto("Inicio"), []);

    const caminosEmpatados = new MyGraph(true);
    caminosEmpatados.agregarArista("A", "B", 2);
    caminosEmpatados.agregarArista("B", "D", 3);
    caminosEmpatados.agregarArista("A", "C", 3);
    caminosEmpatados.agregarArista("C", "D", 2);

    const resultadoEmpatado = Dijkstra.resolver(caminosEmpatados, "A");
    assert.equal(resultadoEmpatado.distancias.get("D"), 5);
    assert.equal(resultadoEmpatado.trayecto("D").at(0), "A");
    assert.equal(resultadoEmpatado.trayecto("D").at(-1), "D");

    assert.throws(
        () => Dijkstra.resolver(grafo, "Fantasma"),
        /El nodo origen: Fantasma no existe/
    );
}

function main(): void {
    testMinPriorityQueue();
    testGraph();
    testDijkstra();
    console.log("Todas las pruebas de Dijkstra pasaron correctamente.");
}

main();
