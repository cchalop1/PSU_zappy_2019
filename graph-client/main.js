const { app, BrowserWindow, ipcMain } = require('electron')
const net = require('net');

let OPTION = {
    port: 4242,
    name: 'GRAPHIC',
    machine: '127.0.0.1'
}

let socket = new net.Socket();

socket.connect(OPTION.port, OPTION.machine, () => {
    console.log('connect to server')
    socket.write('GRAPHIC\n')
    socket.write('msz\n')
})


const data = {
    max_x: -1,
    max_y: -1
}

socket.on('data', (buffer) => {
    buffer.toString().split('\n').map(elem => {
        if (elem.includes('msz')) {
            data.max_x = Number(elem.split(' ')[1])
            data.max_y = Number(elem.split(' ')[2])
        }
    })
})

ipcMain.on('data', (event, arg) => {
    event.returnValue = JSON.stringify(data)
})

const createWindow = () => {
    let win = new BrowserWindow({
        width: 800,
        height: 600,
        frame: false,
        webPreferences: {
            nodeIntegration: true
        }
    })
    win.loadFile('./index.html')
}

app.whenReady().then(createWindow)
