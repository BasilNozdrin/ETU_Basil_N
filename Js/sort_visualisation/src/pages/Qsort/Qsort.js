import React from "react";
import './styles.scss';
import P5 from "p5";
import Math from "math";


import {Navbar} from '../../includes';

export class Qsort extends React.Component {
    constructor(props) {
        super(props);

        let array_size = 10;

        this.initialState = JSON.stringify({
            array_size: array_size,
            array: [...Array(array_size)].map(() => Math.random()),
        });
        this.state = JSON.parse(this.initialState);
    }

    render() {
        return (
            <div style={{display: 'flex', flexDirection: 'column', margin: '0 auto'}}>
                <Navbar/>
                <div style={{display: 'flex', align: 'center'}}>Hello World</div>
            </div>
        );
    }
}

// https://thecodingtrain.com/CodingChallenges/143-quicksort.html
// https://youtu.be/eqo2LxRADhU

let values = [];
let w = 10;

let states = [];
let height = 10,
    width = 10;

function setup() {
    P5.createCanvas(P5.windowWidth, P5.windowHeight);
    values = new Array(Math.floor(width / w));
    for (let i = 0; i < values.length; i++) {
        values[i] = Math.random()%height;
        states[i] = -1;
    }
    quickSort(values, 0, values.length - 1);
}

async function quickSort(arr, start, end) {
    if (start >= end) {
        return;
    }
    let index = await partition(arr, start, end);
    states[index] = -1;

    await Promise.all([
        quickSort(arr, start, index - 1),
        quickSort(arr, index + 1, end)
    ]);
}

async function partition(arr, start, end) {
    for (let i = start; i < end; i++) {
        states[i] = 1;
    }

    let pivotValue = arr[end];
    let pivotIndex = start;
    states[pivotIndex] = 0;
    for (let i = start; i < end; i++) {
        if (arr[i] < pivotValue) {
            await swap(arr, i, pivotIndex);
            states[pivotIndex] = -1;
            pivotIndex++;
            states[pivotIndex] = 0;
        }
    }
    await swap(arr, pivotIndex, end);

    for (let i = start; i < end; i++) {
        if (i !== pivotIndex) {
            states[i] = -1;
        }
    }

    return pivotIndex;
}

function draw() {
    P5.background(0);

    for (let i = 0; i < values.length; i++) {
        P5.noStroke();
        if (states[i] === 0) {
            P5.fill('#E0777D');
        } else if (states[i] === 1) {
            P5.fill('#D6FFB7');
        } else {
            P5.fill(255);
        }
        P5.rect(i * w, height - values[i], w, values[i]);
    }
}

async function swap(arr, a, b) {
    await sleep(50);
    let temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}
