const net = require('net')
// const io = require('socket.io')(server);

const OPTION = {
    port: 4242,
    name: 'name1',
    machine: '127.0.0.1'
}

let socket = new net.Socket();

test('new client', async (done) => {
    socket.connect(OPTION.port, OPTION.machine, () => {
        expect('conect').toBe('conect');
        done()
    })
})

test('welcome client', async (done) => {
    socket.on('data', (data) => {
        expect(data.toString()).toBe('WELCOME\n')
        done()
    })
})

// test('cmd ko', async (done) => {
//     socket.write('toto\n')
//     socket.on('data', (data) => {
//         expect(data.toString()).toBe('ko\n')
//         done()
//     })
// })

afterAll(done => {
    socket.destroy()
    done()
})
