const loginInput = document.querySelector("#login");

document.body.onload = () => {
    loginInput.value = localStorage.login? localStorage.login : "";
};

document.querySelector(".submitButton").onclick = (e) => {
    e.preventDefault();
    if (checkNameEmpty()) {
        window.localStorage.setItem("login", loginInput.value);
        document.querySelector(".loginForm").submit();
    }
}

function checkNameEmpty() {
    if (loginInput.value === "" || loginInput.value.length > 20) {
        loginInput.style.borderColor = "#FF0000"
        return false;
    } else {
        loginInput.style.borderColor = "#000000"
        return true;
    }
}
