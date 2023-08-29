let celciusinput = document.querySelector('#celcius > input')
let fahrenhietinput = document.querySelector('#Fahrenheit > input')
let kelvininput = document.querySelector('#Kelvin > input')

let btn = document.querySelector('.button button')

function roundNumber(number){

    return Math.round(number*100)/100
}

celciusinput.addEventListener('input', function(){
  let ctemp = parseFloat(celciusinput.value)
  let ftemp = (ctemp*(9/5))+32
  let ktemp = ctemp + 273.15

  fahrenhietinput.value = roundNumber(ftemp)
  kelvininput.value = roundNumber(ktemp)

})


fahrenhietinput.addEventListener('input', function(){
    let ftemp = parseFloat(fahrenhietinput.value)
    let ctemp = (ftemp-32)*(5/9)
    let ktemp = (ftemp-32)*(5/9)+273.15
    console.log(ftemp)
    celciusinput.value = roundNumber(ctemp)
    kelvininput.value = roundNumber(ktemp)
  
  })


  kelvininput.addEventListener('input', function(){
    let ktemp = parseFloat(kelvininput.value)
    let ctemp = ktemp-273.15
    let ftemp = (ktemp-273.15) * (9/5) + 32
  
    celciusinput.value = roundNumber(ctemp)
    fahrenhietinput.value = roundNumber(ftemp)
  
  })


  btn.addEventListener('click', ()=>{

    celciusinput.value  
  })
