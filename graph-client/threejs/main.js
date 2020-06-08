const { app, BrowserWindow, ipcMain} = require('electron')

ipcMain.on('msz', (event, arg) => {
    event.returnValue = 'msz 10 10'
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
