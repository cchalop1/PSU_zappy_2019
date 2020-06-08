const { ipcRenderer } = require('electron')

const getMapSize = () => {
    return {
        max_x: Number(ipcRenderer.sendSync('msz', '').split(' ')[1]),
        max_y: Number(ipcRenderer.sendSync('msz', '').split(' ')[2])
    }
}

let scene = new THREE.Scene();
let camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);

let renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

let geometry = new THREE.BoxGeometry();
let material = new THREE.MeshBasicMaterial({ color: 0x00ff00 });
let cube = new THREE.Mesh(geometry, material);
scene.add(cube);


console.log(getMapSize())

camera.position.z = 5;

let animate = function () {
    requestAnimationFrame(animate);

    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;

    renderer.render(scene, camera);
};

animate();
