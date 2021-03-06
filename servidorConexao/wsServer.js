/*
Serial-to-websocket Server
using serialport.js

To call this type the following on the command line:
node wsServer.js portName

where portname is the name of your serial port, e.g. /dev/tty.usbserial-xxxx (on OSX)

created 28 Aug 2015
modified 5 Nov 2017
by Tom Igoe

*/
// include the various libraries that you'll use:
var SerialPort = require('serialport');			// include the serialport library
var winston = require('winston');

var	portName =  process.argv[2];						// get the port name from the command line
var WebSocketServer = require('ws').Server;   // include the webSocket library

// configure the webSocket server:
var SERVER_PORT = 8081;                 // port number for the webSocket server
var wss = new WebSocketServer({port: SERVER_PORT}); // the webSocket server
var connections = new Array;            // list of connections to the server

var myPort = new SerialPort(portName, 9600);// open the port
var Readline = SerialPort.parsers.Readline;	// make instance of Readline parser
var parser = new Readline();								// make a new parser to read ASCII lines
myPort.pipe(parser);													// pipe the serial stream to the parser

// these are the definitions for the serial events:
myPort.on('open', showPortOpen);    // called when the serial port opens
myPort.on('close', showPortClose);  // called when the serial port closes
myPort.on('error', showError);   // called when there's an error with the serial port
parser.on('data', readSerialData);  // called when there's new data incoming


const logFormatter = function(options) {
    // Return string will be passed to logger.

    return (options.message ? options.message : ' ') +
        (options.meta && Object.keys(options.meta).length ?
            '\n\t'+ JSON.stringify(options.meta) : '');
};

const logger = new (winston.Logger)({
    transports: [
        new (winston.transports.File)({
            formatter: logFormatter,
            level: 'silly',
            name: 'fileAll',
            filename: 'log.log',
            json: false                                 // set json:false on the file transport(s)
        })
    ]
});

// ------------------------ Serial event functions:
// this is called when the serial port is opened:
function showPortOpen() {
  console.log("Porta " + portName + " aberta. Velocidade: " + myPort.baudRate);
}

// this is called when new data comes into the serial port:
function readSerialData(data) {
  // if there are webSocket connections, send the serial data
  // to all of them:
  console.log("Recebendo da serial: " + data);
  if (connections.length > 0) {
    broadcast(data);
  }
}

function showPortClose() {
  console.log('Porta fechada.');
}
// this is called when the serial port has an error:
function showError(error) {
  console.log('Erro na porta serial');
}

function sendToSerial(data) {

  var json = JSON.parse(data);

  if(json.TIPO == "LOG"){
    logger.log('silly',"ALERTA"+ " " +json.DATA + " " + json.MENSAGEM);
    console.log("JSON log: " + JSON.stringify(json));
  }else if(json.TIPO=="DADO"){
    myPort.write(data);  
    console.log("Enviado para a serial: " + data);
  }else{
    
  }
}

// ------------------------ webSocket Server event functions
wss.on('connection', handleConnection);

function handleConnection(client) {
  console.log("Nova Conexão");        // you have a new client
  connections.push(client);             // add this client to the connections array

  client.on('message', sendToSerial);      // when a client sends a message,

  client.on('close', function() {           // when a client closes its connection
    console.log("Conexão Encerrada");       // print it out
    var position = connections.indexOf(client); // get the client's position in the array
    connections.splice(position, 1);        // and delete it from the array
  });
}
// This function broadcasts messages to all webSocket clients
function broadcast(data) {
  for (c in connections) {     // iterate over the array of connections
    connections[c].send(data); // send the data to each connection
  }
}