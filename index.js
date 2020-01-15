const inquirer = require('inquirer')
const chalk = require('chalk');

const inOutMessage = msg =>
  console.log(
    chalk.yellow('*'),
    chalk.yellowBright('*'),
    chalk.yellow('*'),
    chalk.yellowBright('*'),
    chalk.yellow('*'),
    chalk.greenBright(msg),
    chalk.yellow('*'),
    chalk.yellowBright('*'),
    chalk.yellow('*'),
    chalk.yellowBright('*'),
    chalk.yellow('*')
  )

const positive = [
  'Świetnie!',
  'Tak to się robi!',
  'I tak dalej!',
  'Mistrz',
  'Ekstra robota',
  'Śmigasz jak Biedronka!!',
  'Hurra',
  'Proste, nie?',
  'Zuch',
  'Łatwizna!',
  'Idziesz jak burza'
]

const negative = [
  'Ups, pomyłeczka',
  'Zdarza się ;)',
  'Spróbuj jeszcze raz',
  'Uczysz się',
  'Skupienie i ciach ciach ciach',
  'Próbuj, próbuj!',
  'Każdemu się zdarza',
  'Trzy wdechy i do dzieła!',
  'A to niespodzianka...',
  'Jeszcze raz'
]

const positiveColors = [
  'green',
  'magenta',
  'blue',
  'bgCyan',
  'bgGreen',
  'bgMagenta'
]

const randomElementOf = msgs =>
  msgs[
    Math.ceil(Math.random() * msgs.length) - 1
  ]

const getNumbers = () => ([
  Math.ceil(Math.random() * 10),
  Math.ceil(Math.random() * 10)
])

const doMath = (a, b, trials) => {
  if (trials === 0) {
    inOutMessage('G R A T U L U J Ę')
    return
  }

  const result = a * b

  inquirer
    .prompt([
      {
        type: 'input',
        name: 'solution',
        message: `${a} * ${b} =`,
        filter: Number
      }
    ])
    .then(({ solution }) => {
      if (solution === result) {
        console.log(
          chalk.yellowBright('***'),
          chalk[
            randomElementOf(positiveColors)
          ](
            randomElementOf(positive)
          ),
          chalk.yellowBright('***'),
          '\n'
        )
        console.log('\n')

        doMath(
          ...getNumbers(),
          trials - 1
        )
      }
      else {
        console.log(
          chalk.redBright(
            randomElementOf(negative)
          ),
          '\n'
        )

        doMath(a, b, trials)
      }
    })
}

inOutMessage('P O U C Z M Y   S I Ę   M A T M Y')
doMath(
  ...getNumbers(),
  Number.parseInt(process.argv[2] || 1)
)
