
document.body.onload = initWindow;

const fieldArray = new Array(20);
const nextElementArray = new Array(6);

const elementSquareSize = 25;
const figureNumberToColor = new Map();
figureNumberToColor.set(1, "#007200");
figureNumberToColor.set(2, "#59E5D2");
figureNumberToColor.set(3, "#FB4D3D");
figureNumberToColor.set(4, "#A40E4C");
figureNumberToColor.set(5, "#FFFFFF");
figureNumberToColor.set(6, "#FF206E");
figureNumberToColor.set(7, "#FBFF12");

const figureWidth = 4;
const figureHeight = 4;
const figures = [
    [[0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0]],
    [[0, 0, 0, 0], [0, 2, 0, 0], [0, 2, 2, 2], [0, 0, 0, 0]],
    [[0, 0, 0, 0], [0, 0, 3, 0], [3, 3, 3, 0], [0, 0, 0, 0]],
    [[0, 0, 0, 0], [0, 4, 4, 0], [0, 4, 4, 0], [0, 0, 0, 0]],
    [[0, 0, 0, 0], [0, 0, 5, 5], [0, 5, 5, 0], [0, 0, 0, 0]],
    [[0, 0, 0, 0], [0, 0, 6, 0], [0, 6, 6, 6], [0, 0, 0, 0]],
    [[0, 0, 0, 0], [0, 7, 7, 0], [0, 0, 7, 7], [0, 0, 0, 0]],
]

let nextFigure = randomFigure();
let curFigure;
let curFigurePositionX;
let curFigurePositionY;

let gameCanvas;
let gameCanvasContext;
const gameCanvasGridHeight = 20;
const gameCanvasGridWidth = 10;
let nextFigureCanvas;
let nextFigureCanvasContext;
const nextFigureCanvasGridHeight = 6;
const nextFigureCanvasGridWidth = 6;

let isGameOver = false;
let isGameStarted = false;
let currentLevel;
let points;
let linesDeleted;
let interval;
let intervalTime;

//region Init functions
function initWindow() {
    setEventListeners();
    setName();
    gameCanvas = document.querySelector('#game_canvas');
    if (gameCanvas.getContext) {
        gameCanvasContext = gameCanvas.getContext('2d');
    }
    nextFigureCanvas = document.getElementById('next_item_canvas');
    if (nextFigureCanvas.getContext) {
        nextFigureCanvasContext = nextFigureCanvas.getContext('2d');
    }
    initGame();
}

function initGame() {
    isGameOver = false;
    isGameStarted = false;
    currentLevel = 1;
    setLevel();
    points = 0;
    setPoints();
    linesDeleted = 0;
    intervalTime = 1000;
    clearArray(fieldArray, gameCanvasGridWidth);
    clearArray(nextElementArray, nextFigureCanvasGridWidth);
    reDrawNextFigure();
    drawStartGameBackground();
}

function setEventListeners() {
    document.addEventListener(
        'keydown',
        (event) => {
            if (!isGameOver && isGameStarted) {
                switch (event.code) {
                    case "ArrowLeft":
                        moveFigureOnSides(-1);
                        break;
                    case "ArrowRight":
                        moveFigureOnSides(1);
                        break;
                    case "ArrowDown":
                        event.preventDefault();
                        dropFigure();
                        break;
                    case "Backspace":

                    case "ArrowUp":
                        event.preventDefault();
                        rotateFigure();
                        break;
                    case "Space":
                        event.preventDefault();
                        dropFigure();
                }
            } else if (!isGameOver && !isGameStarted) {
                if (event.code === "Space") {
                    startGame();
                }
            }
        });
}

function startGame() {
    changeIntervalTime();
    spawnNext();
    isGameStarted = true;
}

//region Util functions
function changeIntervalTime() {
    clearInterval(interval);
    interval = setInterval(() => newStep(), intervalTime);
}

function clearArray(array, width) {
    for (let i = 0; i < array.length; i++) {
        array[i] = arrayOfZeros(width);
    }
}

function arrayOfZeros(length) {
    let tempArray = new Array(length);
    for (let j = 0; j < tempArray.length; j++) {
        tempArray[j] = 0;
    }
    return tempArray;
}

function randomFigure() {
    return figures[Math.floor(Math.random() * figures.length)];
}

function setLevel() {
    document.querySelector("#level").textContent = "Текущий уровень: " + currentLevel
}

function setName() {
    document.querySelector("#username").textContent = "Игрок: " + localStorage["login"]
}

function setPoints() {
    document.querySelector("#points").textContent = "Очки: " + points
}

//region OnGameResume functions
function spawnNext() {
    curFigure = nextFigure;
    nextFigure = randomFigure();
    curFigurePositionY = -1;
    curFigurePositionX = gameCanvasGridWidth / 2 - nextFigureCanvasGridWidth / 2;
    if (stepDown() === false) {
        endGame();
        return;
    }
    reDrawNextFigure();
}

function newStep() {
    if (isGameOver) return;
    if (stepDown() === false) {
        deleteMatchedLines();
        spawnNext();
    }
}

function stepDown() {
    clearPrevPositionOnArray();
    if (checkCollision(curFigurePositionX, curFigurePositionY + 1)) {
        setFigurePosition();
        return false;
    }
    curFigurePositionY = curFigurePositionY + 1;
    setFigurePosition();
    reDrawGameField();
    return true;
}

function deleteMatchedLines() {
    let linesForDelete = [];
    fieldArray.reverse();
    for (let y = 0; y < gameCanvasGridHeight; y++) {
        let counter = 0;
        for (let x = 0; x < gameCanvasGridWidth; x++) {
            if (fieldArray[y][x] !== 0)
                counter++;
        }
        if (counter === gameCanvasGridWidth) {
            linesForDelete.push(y - linesForDelete.length);
        }
    }
    for (let i = 0; i < linesForDelete.length; i++) {
        fieldArray.splice(linesForDelete[i], 1);
        fieldArray.push(arrayOfZeros(10));
        points += 10 * currentLevel;
        linesDeleted++;
        setPoints();
        if (linesDeleted === currentLevel * 10) {
            currentLevel++;
            intervalTime = intervalTime * 0.8;
            changeIntervalTime();
            setLevel();
        }
    }
    fieldArray.reverse();
}

function endGame() {
    isGameOver = true;
    curFigure = null;
    clearInterval(interval);
    addToRecordsIfPass();
    displayRecordsBlock();
}

function recordsComparator(a, b) {
    if (a[1].length !== b[1].length) {
        return b[1].length - a[1].length;
    } else {
        return b[1] - a[1];
    }
}

function addToRecordsIfPass() {
    if (points === 0) return;
    let localStorageEntry = localStorage["tetris.records"];
    let records = [];
    if (localStorageEntry === undefined) {
        records.push([localStorage["tetris.username"], points.toString()]);
    } else {
        records = JSON.parse(localStorageEntry);
        records.push([localStorage["tetris.username"], points.toString()]);
    }
    localStorage["tetris.records"] = JSON.stringify(records.sort(recordsComparator).slice(0, 10));
}

function displayRecordsBlock() {
    let localStorageEntry = localStorage["tetris.records"];
    let recordsTextField = document.querySelector("#records");
    if (localStorageEntry === undefined) {
        recordsTextField.innerText = "Нет рекордов";
    } else {
        let records = JSON.parse(localStorageEntry);
        console.log(records);
        let text = "";
        for (let i = 0; i < records.length; i++) {
            text += i + 1 + ". " + records[i][0] + ", Очки: " + records[i][1] + "\n"
        }
        recordsTextField.innerText = text
    }
    document.querySelector("#game_canvas").style.display = "none"
    document.querySelector("#records_block").style.display = "block"
}

//endregion

//region Modifying array on figure move
function setFigurePosition() {
    for (let x = curFigurePositionX; x < curFigurePositionX + figureWidth; x++) {
        for (let y = curFigurePositionY; y < curFigurePositionY + figureHeight; y++) {
            if (y < 0 || y > gameCanvasGridHeight || x < 0 || x > gameCanvasGridWidth) continue
            if (curFigure[y - curFigurePositionY][x - curFigurePositionX] === 0) continue
            fieldArray[y][x] = curFigure[y - curFigurePositionY][x - curFigurePositionX]
        }
    }
}

function checkCollision(checkX, checkY) {
    for (let y = figureHeight - 1; y >= 0; y--) {
        for (let x = 0; x < figureWidth; x++) {
            if (curFigure[y][x] === 0) continue
            if (checkY + y >= gameCanvasGridHeight) return true
            if (checkX + x < 0) return true
            if (checkX + x >= gameCanvasGridWidth) return true
            if (fieldArray[checkY + y][checkX + x] !== 0) return true
        }
    }
    return false
}

function clearPrevPositionOnArray() {
    if (curFigurePositionY < 0) return
    for (let x = curFigurePositionX; x < curFigurePositionX + figureWidth; x++) {
        for (let y = curFigurePositionY; y < curFigurePositionY + figureHeight; y++) {
            if (y < 0 || y > gameCanvasGridHeight || x < 0 || x > gameCanvasGridWidth) continue
            if (curFigure[y - curFigurePositionY][x - curFigurePositionX] === 0) continue
            fieldArray[y][x] = 0
        }
    }
}

//endregion

//region Draw canvases functions
function reDrawNextFigure() {
    clearCanvas(nextFigureCanvas, nextFigureCanvasContext);
    for (let i = 0; i < nextFigure.length; i++) {
        for (let j = 0; j < nextFigure[i].length; j++) {
            if (nextFigure[i][j] !== 0) {
                nextFigureCanvasContext.fillStyle = figureNumberToColor.get(nextFigure[i][j]);
                nextFigureCanvasContext.fillRect((j + 1) * elementSquareSize, (i + 1) * elementSquareSize, elementSquareSize, elementSquareSize);
            }
        }
    }
    drawGrid(nextFigureCanvasGridWidth, nextFigureCanvasGridHeight, nextFigureCanvasContext);
}

function reDrawGameField() {
    clearCanvas(gameCanvas, gameCanvasContext);
    for (let i = 0; i < fieldArray.length; i++) {
        for (let j = 0; j < fieldArray[i].length; j++) {
            if (fieldArray[i][j] !== 0) {
                gameCanvasContext.fillStyle = figureNumberToColor.get(fieldArray[i][j]);
                gameCanvasContext.fillRect(j * elementSquareSize, i * elementSquareSize, elementSquareSize, elementSquareSize);
            }
            gameCanvasContext.strokeRect(j * elementSquareSize, i * elementSquareSize, elementSquareSize, elementSquareSize);
        }
    }
}

function drawGrid(width, height, context) {
    for (let i = 0; i < width; i++) {
        for (let j = 0; j < height; j++) {
            context.strokeRect(j * elementSquareSize, i * elementSquareSize, elementSquareSize, elementSquareSize);
        }
    }
}

function clearCanvas(canvas, context) {
    context.clearRect(0, 0, canvas.width, canvas.height);
}

function drawStartGameBackground() {
    let img = new Image();
    img.src = "../res/StartGameBackground.svg";
    img.onload = function () {
        gameCanvasContext.drawImage(img, 0, 0);
    };
}


function rotateFigure() {
    clearPrevPositionOnArray();
    let N = figureWidth;
    const clone = (items) => items.map(item => Array.isArray(item) ? clone(item) : item);
    let tempFigure = clone(curFigure);
    for (let i = 0; i < N / 2; i++) {
        for (let j = i; j < N - i - 1; j++) {
            let temp = curFigure[i][j];
            curFigure[i][j] = curFigure[N - 1 - j][i];
            curFigure[N - 1 - j][i] = curFigure[N - 1 - i][N - 1 - j];
            curFigure[N - 1 - i][N - 1 - j] = curFigure[j][N - 1 - i];
            curFigure[j][N - 1 - i] = temp;
        }
    }
    if (checkCollision(curFigurePositionX, curFigurePositionY)) {
        curFigure = tempFigure;
        setFigurePosition();
        return;
    }
    setFigurePosition();
    reDrawGameField();
}

function moveFigureOnSides(side) {
    clearPrevPositionOnArray();
    if (checkCollision(curFigurePositionX + side, curFigurePositionY)) {
        setFigurePosition();
        return;
    }
    curFigurePositionX = curFigurePositionX + side;
    setFigurePosition();
    reDrawGameField();
    return true
}

function dropFigure() {
    while (stepDown()) {}
    setTimeout(() => newStep(), 300);
}

function goToLogin() {
    window.location = "../index.html";
}
