pipeline {
    agent any
    environment {
        CI = 'true'
    }
    stages {
        stage('Build') {
            steps {
                echo 'building...'
            }
        }
        stage('Test') {
            when {
                branch 'development'
            }
            steps {
                echo 'testing...'
                sh '~/test.sh'
            }
        }
    }
}
