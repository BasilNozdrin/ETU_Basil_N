import React from "react";
import './styles.scss';

// import refreshSVG from "./media/refresh.svg";
import refreshSVG from "./media/refresh2.svg";

import {Cell} from "./Cell";
import {Navbar} from "../../includes";

export class Game extends React.Component {
    constructor(props) {
        super(props);
        this.initialState = JSON.stringify({
            field: [...Array(3).keys()]
                .map(() => (
                        [...Array(3).keys()]
                            .map(() => 0)
                    )
                ),
            player: 1,
            rotating: false,
        });
        this.state = JSON.parse(this.initialState);
    }

    checkState() {
        let {field} = this.state;
        for (let i = 0; i < 3; i++) {
            if (field[i][0] && field[i][0] === field[i][1] && field[i][1] === field[i][2])
                    return true;
            if (field[0][i] && field[0][i] === field[1][i] && field[1][i] === field[2][i])
                    return true;
        }
        return field[1][1] && ((field[0][0] === field[1][1] && field[2][2] === field[1][1]) ||
            (field[0][2] === field[1][1] && field[2][0] === field[1][1]));
    }

    restart() {
        this.setState({...JSON.parse(this.initialState), rotating: true}, () => {
            setTimeout(() => {
                this.setState({rotating: false})
            }, 1000)
        });
    }

    turn(x, y) {
        let {field: newField, player: newPlayer} = this.state;
        if (!newField[x][y] && newPlayer) {
            newField[x][y] = newPlayer;
            newPlayer = (newPlayer === 1) ? 2 : 1;
        }
        this.setState({
            field: newField,
            player: newPlayer,
        });
        if (this.checkState())
             this.setState({
                 player: 0,
             });
    }

    render() {
        const {rotating} = this.state;
        return (
            <div style={{display: 'flex', flexDirection: 'column', margin: '0 auto'}}>
                <Navbar/>
                <div className="game-title">
                    <div>
                        <span style={{color: '#008080', fontWeight: 'bold'}}>Restart</span>
                        <img className={`${rotating ? 'rotating' : ''}`} onClick={this.restart.bind(this)} src={refreshSVG} alt="refresh"/>
                    </div>
                </div>
                <div className="field">
                    {this.state.field.map(
                        (item, index) => (
                            <div key={index} className="row">
                                {
                                    item.map
                                    (
                                        ( item, number) =>
                                            (
                                                <Cell key={number} num={item} nextTurn={() => {this.turn(index, number)}}/>
                                            )
                                    )
                                }
                            </div>
                        )
                    )}
                </div>
            </div>
        );
    }
}
