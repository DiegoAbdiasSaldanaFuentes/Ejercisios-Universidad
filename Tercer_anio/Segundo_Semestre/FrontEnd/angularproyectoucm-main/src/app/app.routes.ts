import { Routes } from '@angular/router';
import { Home } from './pages/home/home';
import { Historia } from './pages/historia/historia';
import { Contacto } from './pages/contacto/contacto';
import { Login } from './pages/login/login';
import {Perfil} from './pages/perfil/perfil';

export const routes: Routes = [
  {
    path: '',
    redirectTo: 'inicio',
    pathMatch: 'full'
  },
  {
    path: 'inicio',
    component: Home,
    title: 'Inicio - Mi sitio'
  },
  {
    path: 'historia',
    component: Historia,
    title: 'Historia - Mi sitio'
  },
  {
    path: 'contacto',
    component: Contacto,
    title: 'Contacto - Mi sitio'
  },
  {
    path: 'login',
    component: Login,
    title: 'Login - Mi sitio'
  },
  {
    path: 'perfil',
    component: Perfil,
    title: 'Perfil - Mi sitio'
  },
  {
    path: '**',
    redirectTo: 'inicio'
  }


];
