const { ipcRenderer } = require('electron')

let scene = new THREE.Scene();
let camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);

let renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

let data = JSON.parse(ipcRenderer.sendSync('data',''))

let geometry = new THREE.PlaneGeometry(data.max_x, data.max_y, 30);
let material = new THREE.MeshBasicMaterial({ color: 0x228B22, side: THREE.DoubleSide });
let plane = new THREE.Mesh(geometry, material);

plane.rotation.x = 1.60
scene.add(plane);

camera.position.z = 8;
camera.position.y = 2;

let animate = () => {
    requestAnimationFrame(animate);

    plane.rotation.z += 0.003;
    console.log(plane.rotation.x)
    renderer.render(scene, camera);
};

// animate()
renderer.render(scene, camera);
