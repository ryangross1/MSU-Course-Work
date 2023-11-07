const count = document.getElementById("count");
const intBtn = document.getElementById("intBtn");

let countState = 0;
function incCount() {
    countState++;
    count.innerText = countState;
}
incBtn.addEventListener('click', incCount)