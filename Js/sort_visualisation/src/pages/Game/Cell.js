import React from "react";

// import crossSVG from './media/times.svg';
// import circleSVG from './media/circle.svg';

import crossSVG from './media/times2.svg';
import circleSVG from './media/circle2.svg';

export class Cell extends React.Component {
    render() {
        const {num, nextTurn} = this.props;
        const tiles = [null, <img src={crossSVG} alt="cross"/>, <img src={circleSVG} alt="cross"/>];
        return (
            <div onClick={nextTurn} className="cell">
                {tiles[num]}
            </div>
        );
    }
}
