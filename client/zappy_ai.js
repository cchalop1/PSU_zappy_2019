#!/usr/bin/env node
const net = require('net');

const client = new net.Socket();

client.connect(4242, '127.0.0.1', () => {
    console.log('Connected');
    client.write('Hello, server! Love, Client.');
});

client.on('data', (data) => {
    console.log('Received: ' + data);
    client.destroy();
});

client.on('close', () => {
    console.log('Connection closed');
});