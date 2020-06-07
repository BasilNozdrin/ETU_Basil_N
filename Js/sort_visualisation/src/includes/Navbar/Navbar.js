import React from "react";
import './styles.scss';

import logoSVG from './media/logo.svg';

export class Navbar extends React.Component {

    render() {
        return (
            <div className="navbar">
                <div className="logo">
                    <img src={logoSVG} alt="logo"/>
                    <span className="title"/>
                </div>
            </div>
        );
    }
}
