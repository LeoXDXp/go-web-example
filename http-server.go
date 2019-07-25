// https://gobyexample.com/http-servers
// Writing a basic HTTP server is easy using the `net/http` packedad.
package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	//"github.com/hybridgroup/mjpeg"
	//tf "github.com/tensorflow/tensorflow/tensorflow/go"
	//"github.com/tensorflow/tensorflow/tensorflow/go/op"
	//"gocv.io/x/gocv"
)

type Personaje struct {
	Nombre   string `json:"nombre"`
	Apellido string `json:"apellido"`
	Edad     int    `json:"edad"`
}

// Descripcion de la funcion, sus parametros de entrada y la salida esperada
func hello(w http.ResponseWriter, req *http.Request) {
	// Con navegadores como firefox, al cargar JSON se puede utilizar filtros
	jsonData, err := json.Marshal("hello")
	if err != nil {
		http.Error(w, "500", http.StatusInternalServerError)
	} else {
		// Set Content-Type header so that clients will know how to read response
		w.Header().Set("Content-Type", "application/json")
		w.WriteHeader(http.StatusOK)
		w.Write(jsonData)
	}
}

// curl -s -XPOST -d'{"nombre":"Pepe","apellido":"Cortisona","edad":40}' http://localhost:8090/decode
func decode(w http.ResponseWriter, req *http.Request) {
	var user Personaje
	json.NewDecoder(req.Body).Decode(&user)
	fmt.Fprintf(w, "%s %s tiene %d años!", user.Nombre, user.Apellido, user.Edad)
	log.Printf("Un usuario indica que %s %s tiene %d años!", user.Nombre, user.Apellido, user.Edad)
}

func index(w http.ResponseWriter, req *http.Request) {
	mapData := map[string]map[string]string{"Nuevo Link": map[string]string{"nombre": "/decode", "tipo": "json"},
		"Antiguo Link": map[string]string{"nombre": "/hello", "tipo": "http"}}
	jsonData, err := json.Marshal(mapData)
	if err != nil {
		http.Error(w, "500", http.StatusInternalServerError)
	} else {
		// Set Content-Type header so that clients will know how to read response
		w.Header().Set("Content-Type", "application/json")
		w.WriteHeader(http.StatusOK)
		w.Write(jsonData)
	}
	//fmt.Fprintf(w, "Puede revisar /hello o /headers \n")
}

func main() {

	log.Printf("Running")
	http.HandleFunc("/hello", hello)
	http.HandleFunc("/decode", decode)
	http.HandleFunc("/", index)

	// Finally, we call the `ListenAndServe` with the port
	// and a handler. `nil` tells it to use the default
	// router we've just set up.
	log.Fatal(http.ListenAndServe(":8090", nil))
}
