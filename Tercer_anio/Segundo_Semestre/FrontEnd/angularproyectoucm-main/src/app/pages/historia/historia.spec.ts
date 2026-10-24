import { ComponentFixture, TestBed } from '@angular/core/testing';
import { Historia } from './historia';

describe('Historia', () => {
  let component: Historia;
  let fixture: ComponentFixture<Historia>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [Historia],
    }).compileComponents();

    fixture = TestBed.createComponent(Historia);
    component = fixture.componentInstance;
    await fixture.whenStable();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
